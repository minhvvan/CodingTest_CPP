#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;

    set<string> strSet(strs.begin(), strs.end());
    const int N = t.length();
    vector<int> dp(N+1, INT_MAX);

    dp[N] = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        string temp;
        for(int j = 0 ; i + j < N && j < 5; j++)
        {
            temp += t[i+j];
            if(strSet.find(temp) != strSet.end() && dp[i + j + 1] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i + j + 1] + 1);
            }
        }
    }
    
    if(dp[0] == INT_MAX) return -1;
    else return dp[0];
}