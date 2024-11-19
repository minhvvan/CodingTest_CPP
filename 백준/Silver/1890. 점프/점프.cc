#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    vector<vector<int>> nums(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> nums[i][j];
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (nums[i][j] == 0) continue;

            int rightY = i;
            int rightX = j + nums[i][j];

            if (rightY >= 0 && rightY < N && rightX >= 0 && rightX < N)
            {
                dp[rightY][rightX] += dp[i][j];
            }

            int downY = i + nums[i][j];
            int downX = j;

            if (downY >= 0 && downY < N && downX >= 0 && downX < N)
            {
                dp[downY][downX] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}