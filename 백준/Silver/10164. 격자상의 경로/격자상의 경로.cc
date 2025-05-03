#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, K;
vector<vector<int>> dp;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M >> K;

    dp.resize(N + 1, vector<int>(M + 1, 0));
    dp[1][1] = 1;

    int y = K / M + 1;
    int x = K % M;
    if (K % M == 0)
    {
        y--;
        x = M;
    }

    if (K == 0)
    {
        y = N;
        x = M;
    }

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
        }
    }

    for (int i = y; i <= N; i++)
    {
        for (int j = x; j <= M; j++)
        {
            if (i == y && j == x) continue;
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[N][M];

    return 0;
} 