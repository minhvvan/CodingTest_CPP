#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> M;

    vector<vector<int>> dp(N, vector<int>(N, 0));
    set<pair<int, int>> points;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        points.insert({ a,b });
    }

    dp[0][0] = 1;

    //row가 같으면 정답은 0임
    int row = 1;
    for (auto itr = points.begin(); itr != points.end(); itr++)
    {
        auto [y, x] = *itr;

        for (; row <= y; row++)
        {
            for (int j = 0; j <= row; j++)
            {
                dp[row][j] += dp[row - 1][j];
                if (j - 1 >= 0)
                {
                    dp[row][j] += dp[row - 1][j - 1];
                }

                if (row == y && j != x) dp[row][j] = 0;
            }
        }
    }

    for (int i = row; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0)
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j < N; j++)
    {
        ans += dp[N - 1][j];
    }

    cout << ans;

    return 0;
}