#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> dp;
vector<vector<bool>> visited;
int ans = 0;

vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

void dfs(int y, int x, int depth)
{
    for (int i = 0; i < 4; i++)
    {
        int newY = y + dy[i] * board[y][x];
        int newX = x + dx[i] * board[y][x];

        if (newY < 0 || newY >= N || newX < 0 || newX >= M)
        {
            ans = max(ans, depth + 1);
            continue;
        }
        if (board[newY][newX] == 'H'-'0')
        {
            ans = max(ans, depth + 1);
            continue;
        }
        if (visited[newY][newX])
        {
            cout << -1;
            exit(0);
        }

        if (depth + 1 <= dp[newY][newX]) continue;
        dp[newY][newX] = depth + 1;

        visited[newY][newX] = true;
        dfs(newY, newX, depth+1);
        visited[newY][newX] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    board.resize(N);
    visited.resize(N, vector<bool>(M, false));
    dp.resize(N, vector<int>(M, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            board[i].push_back(str[j] - '0');
        }
    }

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}