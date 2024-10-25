#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> trains;
vector<int> sums;
vector<vector<int>> dp;
const int TRAIN_NUM = 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    
    cin >> N;
    trains.resize(N+1, 0);
    sums.resize(N+1, 0);
    dp.resize(4, vector<int>(N+1, 0));

    for (int i = 1; i <= N; i++)
    {
        cin >> trains[i];
        if (i == 0) sums[i] = trains[i];
        else sums[i] += sums[i - 1] + trains[i];
    }

    cin >> M;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < M)
            {
                dp[i][j] = sums[j];
                continue;
            }

            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + sums[j] - sums[j - M]);
        }
    }

    cout << dp[3][N];

    return 0;
}