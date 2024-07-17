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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    vector<int> Coins(N, 0);
    vector<int> dp(K+1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> Coins[i];
    }

    dp[0] = 1;

    for (auto coin : Coins)
    {
        for (int i = coin; i <= K; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[K];

    return 0;
}