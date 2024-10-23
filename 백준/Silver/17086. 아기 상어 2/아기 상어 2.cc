#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> space;
vector<vector<bool>> visited;

vector<int> dy = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector<int> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };

int bfs(int i, int j)
{
    fill(visited.begin(), visited.end(), vector<bool>(M, false));

    queue<pair<int, int>> q;
    q.push({ i ,j });
    visited[i][j] = true;

    int dist = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int t = 0; t < size; t++)
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
                if (space[newY][newX] == 1) return dist;
                if (visited[newY][newX]) continue;

                visited[newY][newX] = true;
                q.push({ newY, newX });
            }
        }

        dist++;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    space.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> space[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (space[i][j] == 1) continue;
            ans = max(ans, bfs(i, j));
        }
    }

    cout << ans;

    return 0;
}