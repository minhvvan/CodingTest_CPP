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
const int MAX = 10'001;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    vector<int> Coins(N);
    vector<int> dp(K + 1, MAX);

    for (int i = 0; i < N; i++)
    {
        cin >> Coins[i];
        dp[Coins[i]] = 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= K; i++)
    {
        for (auto coin : Coins)
        {
            if (i - coin < 0) continue;

            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if (dp[K] == MAX) cout << -1;
    else cout << dp[K];

    return 0;
}