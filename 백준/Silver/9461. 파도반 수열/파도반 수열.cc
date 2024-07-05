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

int T, N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    vector<long long> dp(101, 0);

    //1, 1, 1, 2, 2, 3, 4, 5, 7, 9
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    while (T-- > 0)
    {
        cin >> N;

        for (int i = 6; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 5];
        }

        cout << dp[N] << "\n";
    }

    return 0;
}