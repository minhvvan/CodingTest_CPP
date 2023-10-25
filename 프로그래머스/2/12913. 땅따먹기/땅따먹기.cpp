#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    vector<vector<int>> dp(land.size(), vector<int>(land[0].size(), 0));
    
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for(int i = 1 ; i < land.size(); i++)
    {
        for(int j = 0 ; j < land[i].size(); j++)
        {
            int tempMax = 0;
            for(int k = 0; k < 4; k++)
            {
                if(k == j) continue;
                tempMax = max(tempMax, dp[i-1][k]);
            }
            
            dp[i][j] = land[i][j] + tempMax;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        answer = max(answer, dp[land.size()-1][i]);
    }

    return answer;
}