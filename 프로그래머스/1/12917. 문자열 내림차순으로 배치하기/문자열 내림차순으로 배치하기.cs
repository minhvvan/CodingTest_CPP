using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string solution(string s) {
        string answer = "";
        
        List<char> temp = new List<char>();
        
        foreach(var c in s)
        {
            temp.Add(c);
        }
        
        temp.Sort();
        temp.Reverse();
        
        foreach(var c in temp)
        {
            answer += c;
        }
        
        return answer;
    }
}