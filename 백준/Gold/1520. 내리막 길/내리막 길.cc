#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int N, M;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

vector<vector<int>> Board;
vector<vector<int>> dp;

int dfs(int y, int x)
{
    if (y == N && x == M) return 1;
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (newY <= 0 || newY > N || newX <= 0 || newX > M) continue;
        if (Board[newY][newX] < Board[y][x])
        {
            dp[y][x] += dfs(newY, newX);
        }
    }

    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    Board.assign(N + 1, vector<int>(M + 1));
    dp.assign(N + 1, vector<int>(M + 1, -1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Board[i][j];
        }
    }

    cout << dfs(1, 1) << "\n";

    return 0;
}