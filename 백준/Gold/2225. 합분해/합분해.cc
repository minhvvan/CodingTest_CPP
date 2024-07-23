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

int N, K;
const int DIV = 1'000'000'000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) %  DIV;
            }
        }
    }

    cout << dp[K][N];

    return 0;
}