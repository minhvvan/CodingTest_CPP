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
#include <list>
#include <bitset>

using namespace std;

int N;
vector<int> children;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    children.resize(N);
    dp.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> children[i];
        dp[i] = 1;
    }

    //make LIS
    int ans = N;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (children[j] < children[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        ans = min(ans, N - dp[i]);
    }

    cout << ans;

    return 0;
}