using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string solution(string s) {
        string answer = "";
        
        var nums = s.Split(' ').Select(int.Parse).ToList();
        
        int min = nums.Min();
        int max = nums.Max();
        
        return $"{min} {max}";
    }
}