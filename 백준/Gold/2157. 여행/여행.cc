#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, K;

vector<vector<pair<int,int>>> paths;
vector<vector<int>> dp;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M >> K;

    paths.resize(N + 1);
    dp.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) continue;    
        paths[a].push_back({ b,c });
    }

    for (int i = 0; i < paths[1].size(); i++)
    {
        auto [next, score] = paths[1][i];
        dp[next][2] = max(dp[next][2], score);
    }

    for (int k = 2; k <= M; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (dp[i][k] == 0) continue;

            for (int j = 0; j < paths[i].size(); j++)
            {
                auto [next, score] = paths[i][j];
                dp[next][k + 1] = max(dp[next][k + 1], dp[i][k] + score);
            }
        }
    }


    int ans = 0;

    for (int i = 1; i <= M; i++)
    {
        ans = max(ans, dp[N][i]);
    }

    cout << ans;

    return 0;
} 