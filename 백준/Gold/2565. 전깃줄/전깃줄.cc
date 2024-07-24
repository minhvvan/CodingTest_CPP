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
    vector<pair<int, int>> Nums;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        Nums.push_back({ a,b });
    }

    sort(Nums.begin(), Nums.end());

    int ans = 0;
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Nums[j].second < Nums[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }


    cout << N - ans;

    return 0;
}