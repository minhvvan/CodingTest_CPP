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
    if (N % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> dp(N+1, 0);

    dp[0] = 1;
    dp[2] = 3;

    for (int n = 3; n <= N; n++)
    {
        if (n % 2 != 0)
        {
            dp[n] = 0;
        }
        else
        {
            for (int i = 2; i <= N; i += 2)
            {
                if (i == 2) dp[n] = dp[n - i] * dp[2];
                else if ((n - i) >= 0) dp[n] += dp[n - i] * 2;
            }
        }
    }

    cout << dp[N];

    return 0;
}