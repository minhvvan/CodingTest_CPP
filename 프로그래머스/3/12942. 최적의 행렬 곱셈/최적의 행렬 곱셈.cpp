#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = INT_MAX;
    int size = matrix_sizes.size();
    
    vector<vector<int>> dp(size, vector<int>(size, 0));
    
    for(int i = 0 ; i < size ; i++) dp[i][i] = 0;
    
    for(int i = 1 ; i < size ; i++)
    {
        int end;
        for(int start = 0 ; start < size ; start++)
        {
            end = i + start;
            
            if(end >= size) break;
            
            dp[start][end] = INT_MAX;
            for(int sp = start ; sp < end ; sp++)
            {
                dp[start][end] = min(dp[start][end], dp[start][sp] + dp[sp+1][end] + (matrix_sizes[start][0] * matrix_sizes[sp+1][0] * matrix_sizes[end][1]));
            }
        }
    }    
    
    return dp[0][size-1];
}