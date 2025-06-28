using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int n, int[] stations, int w){
        int answer =0;
        List<int> gaps = new List<int>();
        
        int start = 1;
        
        foreach(var station in stations)
        {
            int left = station - w;
            int right = station + w;
            if(left <= 1) left = 1;
            if(right >= n) right = n;
            
            int gap = left - start;
            if(gap < 0) gap = 0;
            gaps.Add(gap);
            start = right + 1;
        }
        
        if(start <= n)
        {
            gaps.Add(n - start + 1);
        }
        
        int range = w * 2 + 1;
        foreach(var gap in gaps)
        {
            int added = gap / range;
            if(gap % range != 0) added++;
            answer += added;
        }
        
        return answer;
    }
}