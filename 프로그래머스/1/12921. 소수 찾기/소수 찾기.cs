using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    List<bool> isPrime;
    
    public int solution(int n) {
        int answer = 0;
        isPrime = Enumerable.Repeat(true, n + 1).ToList();
        
        for(int i = 2; i * i <= n; i++)
        {
            for(int j = i * 2; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
        
        for(int i = 2; i <= n; i++)
        {
            if(isPrime[i]) answer++;
        }
        
        return answer;
    }
}