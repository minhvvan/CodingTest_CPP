#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> board;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int BFS()
{
    vector<vector<vector<bool>>> visited(N + 1, vector<vector<bool>>(M + 1, vector<bool>(11, false)));

    queue<tuple<int, int, int, int>> q;
    q.push({ 1,1,1,K });

    while (!q.empty())
    {
        auto [y, x, cost, k] = q.front();
        q.pop();

        if (y == N && x == M) return cost;

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 1 || newY > N || newX < 1 || newX > M) continue;

            if (board[newY][newX] == 1)
            {
                if (k == 0) continue;
                if (visited[newY][newX][k+1]) continue;
                visited[newY][newX][k + 1] = true;

                q.push({ newY, newX, cost + 1, k - 1 });
            }
            else
            {
                if (visited[newY][newX][k]) continue;
                visited[newY][newX][k] = true;
                q.push({ newY, newX, cost + 1, k });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M >> K;

    board.resize(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++)
        {
            board[i][j] = str[j-1] - '0';
        }
    }

    cout << BFS();

    return 0;
}