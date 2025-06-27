using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        SortedDictionary<int,int> pq = new SortedDictionary<int,int>();
        
        foreach(var work in works)
        {
            pq[-work] = pq.GetValueOrDefault(-work, 0) + 1;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(pq.Count == 0) break;  
            
            var top = pq.First();
            int maxWork = -top.Key; 
            
            if(--pq[top.Key] == 0) pq.Remove(top.Key);
            
            if(maxWork > 1) {
                int newWork = maxWork - 1;
                pq[-newWork] = pq.GetValueOrDefault(-newWork, 0) + 1;
            }
        }
        
        foreach(var pair in pq)
        {
            int work = -pair.Key;
            int count = pair.Value;
            answer += (long)work * work * count;
        }
        
        return answer;
    }
}