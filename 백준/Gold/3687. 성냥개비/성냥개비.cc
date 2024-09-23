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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int N, T;
vector<long long> dp;
vector<vector<int>> matchsticks;

void makeMax(int num, vector<int>& nums)
{
    if (num == 0) return;

    if (num == 3) 
    {
        nums.push_back(7);
        return;
    }

    nums.push_back(1);
    makeMax(num - 2, nums);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    dp.resize(101, LLONG_MAX);
    int min_num[8] = { 0,0,1,7,4,2,0,8 };

    dp[1] = 9;
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;

    //makeMin
    for (int i = 8; i <= 100; ++i)
    {
        for (int j = 2; j <= 7; ++j)
        {
            dp[i] = min(dp[i], dp[i - j] * 10 + min_num[j]);
        }
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp[N] << " ";

        //makeMax
        vector<int> maxNums;
        makeMax(N, maxNums);
        for (auto itr = maxNums.rbegin(); itr != maxNums.rend(); itr++)
        {
            cout << *itr;
        }

        cout << "\n";
    }

    return 0;
}