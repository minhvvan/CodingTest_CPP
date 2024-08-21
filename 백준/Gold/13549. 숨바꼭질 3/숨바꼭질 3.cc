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

int N, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    const int MAX = 100'001;
    vector<int> dp(MAX, INT_MAX);

    dp[N] = 0;
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        //left
        if (current - 1 >= 0)
        {
            if (dp[current - 1] > dp[current] + 1)
            {
                dp[current - 1] = dp[current] + 1;
                q.push(current - 1);
            }
        }

        //right
        if (current + 1 < MAX)
        {
            if (dp[current + 1] > dp[current] + 1)
            {
                dp[current + 1] = dp[current] + 1;
                q.push(current + 1);
            }
        }

        //teleport
        if (current * 2 < MAX)
        {
            if (dp[current * 2] > dp[current])
            {
                dp[current * 2] = dp[current];
                q.push(current * 2);
            }
        }
    }

    cout << dp[K];

    return 0;
}