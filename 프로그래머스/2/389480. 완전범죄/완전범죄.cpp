#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 120 + 12;
vector<vector<bool>> dp(MAX, vector<bool>(MAX, false));

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    dp[0][0] = true;
    
    for(int i = 0 ; i < info.size(); i++)
    {
        int A = info[i][0];
        int B = info[i][1];
        
        int temp[MAX][MAX] = {false, };
        
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < m; x++)
            {
                if(!dp[y][x]) continue;
                
                if(y + A < n)
                {
                    temp[y+A][x] = true;
                }
                
                if(x + B < m)
                {
                    temp[y][x + B] = true;
                }
            }
        }
        
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < m; x++)
            {
                dp[y][x] = temp[y][x];
            }
        }
    }
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            if(dp[y][x])
            {
                return y;
            }
        }
    }
    
    return -1;
}