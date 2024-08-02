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
const long long MAX = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> dists(N - 1);
    vector<int> costs(N);
    for (int i = 0; i < N - 1; i++)
    {
        int d;
        cin >> d;
        if (i == 0) dists[i] = d;
        else dists[i] = dists[i - 1] + d;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    vector<long long> dp(N, MAX);
    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int dist = dists[i - 1];
            int minus = 0;
            if(j != 0) minus = dists[j - 1];
            dist -= minus;

            dp[i] = min(dp[i], dp[j] + dist * costs[j]);
        }
    }

    cout << dp[N - 1];

    return 0;
}