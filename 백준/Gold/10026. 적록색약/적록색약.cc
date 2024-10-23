#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<char>> picture;
vector<vector<bool>> visited;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void print(vector<vector<bool>>& visited)
{
    for (auto& row : visited)
    {
        for (auto c : row)
        {
            if (c) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(string current, int i, int j)
{
    queue<pair<int, int>> q;
    
    q.push({ i, j });
    visited[i][j] = true;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
            if (visited[newY][newX]) continue;
            if (current.find(picture[newY][newX]) == string::npos) continue;

            visited[newY][newX] = true;
            q.push({ newY, newX });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    picture.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> picture[i][j];
        }
    }

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;
            string current;
            current += picture[i][j];

            bfs(current, i, j);
            negative++;
        }
    }

    fill(visited.begin(), visited.end(), vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            string current;
            if (visited[i][j]) continue;

            if (picture[i][j] == 'R' || picture[i][j] == 'G')
            {
                current = "RG";
            }
            else
            {
                current = "B";
            }

            bfs(current, i, j);
            positive++;
        }
    }

    cout << negative << " " << positive;

    return 0;
}