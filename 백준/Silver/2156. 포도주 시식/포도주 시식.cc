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

    vector<int> wines(N+1);
    for (int i = 1; i <= N; i++)
    {
        cin >> wines[i];
    }

    vector<int> dp(N+1, 0);

    dp[0] = 0;
    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];

    for (int i = 3; i <= N; i++) 
    {
        dp[i] = max({ dp[i - 3] + wines[i - 1] + wines[i], dp[i - 2] + wines[i], dp[i - 1] });
    }

    cout << dp[N];
    return 0;
}