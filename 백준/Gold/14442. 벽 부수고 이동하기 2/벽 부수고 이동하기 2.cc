#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<string> board;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int BFS()
{
    vector<vector<vector<int>>> visited(N + 1, vector<vector<int>>(M + 1, vector<int>(11, -1)));

    queue<tuple<int, int, int>> q;
    q.push({ 1,1,0 });
    visited[1][1][0] = 1;

    while (!q.empty())
    {
        auto [y, x, k] = q.front();
        q.pop();

        if (y == N && x == M)
        {
            return visited[y][x][k];
        }

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 1 || newY > N || newX < 1 || newX > M) continue;

            if (board[newY][newX] == '1')
            {
                if (k == K) continue;
                if (visited[newY][newX][k+1] != -1) continue;
                visited[newY][newX][k + 1] = visited[y][x][k] + 1;

                q.push({ newY, newX, k + 1 });
            }
            else
            {
                if (visited[newY][newX][k] != -1) continue;
                visited[newY][newX][k] = visited[y][x][k] + 1;

                q.push({ newY, newX, k });
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

    board.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        board[i] = "0" + str;
    }

    cout << BFS();

    return 0;
}