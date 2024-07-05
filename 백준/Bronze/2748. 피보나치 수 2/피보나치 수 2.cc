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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<long long> dp(N+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N];
    return 0;
}