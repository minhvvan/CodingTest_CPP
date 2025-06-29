using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        
        var nums = new List<(int, int)>();
        
        foreach(var a in A)
        {
            nums.Add((a, 1));
        }
        
        foreach(var b in B)
        {
            nums.Add((b, 0));
        }
        
        nums.Sort();
        
        int Acnt = 0;
        for(int i = 0 ; i < nums.Count; i++)
        {
            var num = nums[i].Item1;
            var type = nums[i].Item2;
            
            if(type == 1) Acnt++;
            else 
            {
                if(Acnt > 0)
                {
                    answer++;
                    Acnt--;
                }
            }
        }
        
        return answer;
    }
}