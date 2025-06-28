using System;
using System.Linq;
using System.Collections.Generic;

class Solution
{
    public int solution(int[] sticker)
    {
        if(sticker.Length == 1)
        {
            return sticker[0];
        }
        
        int answer = 0;
        
        int N = sticker.Length;
        int[,] dp = new int[2, N];
        
        // 0번을 뜯을 때
        dp[0, 0] = sticker[0];
        dp[0, 1] = Math.Max(dp[0, 0], sticker[1]);
        for(int i = 2; i < N - 1; i++)
        {
            dp[0, i] = Math.Max(dp[0, i-1], dp[0, i-2] + sticker[i]);
        }
        dp[0, N-1] = dp[0, N-2];
        
        // 0번을 안뜯을 때
        dp[1, 1] = sticker[1];
        for(int i = 2; i < N; i++)
        {
            dp[1, i] = Math.Max(dp[1, i-1], dp[1, i-2] + sticker[i]);
        }
        
        answer = Math.Max(dp[0, N-1], dp[1, N-1]);

        return answer;
    }
}