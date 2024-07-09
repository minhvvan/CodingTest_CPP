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
int MAX = 100'001;
vector<int> dp(MAX, INT_MAX);


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    
    if (N == K)
    {
        cout << 0 << "\n";
        cout << N;
        return 0;
    }

    dp[N] = 0;
    queue<pair<int, vector<int>>> q;
    q.push({ N, {N} });
    while (!q.empty())
    {
        auto [current, log] = q.front();
        q.pop();

        if (current + 1 < MAX)
        {
            if (dp[current + 1] == INT_MAX)
            {
                dp[current + 1] = dp[current] + 1;
                log.push_back(current + 1);
                q.push({ current + 1, log });

                if (current + 1 == K)
                {
                    cout << dp[current + 1] << "\n";
                    for (auto num : log)
                    {
                        cout << num << " ";
                    }

                    return 0;
                }

                log.pop_back();
            }
        }

        if (current - 1 >= 0)
        {
            if (dp[current - 1] == INT_MAX)
            {
                dp[current - 1] = dp[current] + 1;
                log.push_back(current - 1);
                q.push({ current - 1, log });

                if (current - 1 == K)
                {
                    cout << dp[current - 1] << "\n";
                    for (auto num : log)
                    {
                        cout << num << " ";
                    }

                    return 0;
                }

                log.pop_back();
            }
        }
            
        if (current * 2 < MAX)
        {
            if (dp[current * 2] == INT_MAX)
            {
                dp[current * 2] = dp[current] + 1;
                log.push_back(current * 2);
                q.push({ current * 2, log });

                if (current * 2 == K)
                {
                    cout << dp[current * 2] << "\n";
                    for (auto num : log)
                    {
                        cout << num << " ";
                    }

                    return 0;
                }

                log.pop_back();
            }
        }
    }

    return 0;
}