using System.Collections.Generic;
using System;

public class Solution {
    public bool solution(string s) {
        bool answer = true;
        
        int len = s.Length;
        if(len != 4 && len != 6)
        {
            return false;
        }
        
        foreach(var c in s)
        {
            if(c - '0' < 0 || c - '0' > 9)
            {
                return false;
            }
        }
        
        return answer;
    }
}