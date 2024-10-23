#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt = 0, maxArea = 0;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void bfs(vector<vector<int>>& picture, vector<vector<bool>>& visited, int i, int j)
{
    queue<pair<int, int>> q;

    q.push({ i,j });
    visited[i][j] = true;

    int area = 0;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        area++;

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (visited[newY][newX]) continue;
            if (picture[newY][newX] == 0) continue;

            visited[newY][newX] = true;
            q.push({ newY, newX });
        }
    }

    maxArea = max(maxArea, area);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    vector<vector<int>> picture(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> picture[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j]) continue;
            if (picture[i][j] == 0) continue;

            bfs(picture, visited, i, j);

            cnt++;
        }
    }

    cout << cnt << "\n" << maxArea;

    return 0;
}