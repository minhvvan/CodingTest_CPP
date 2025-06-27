using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string[] solution(string[] strings, int n) {
        Array.Sort(strings);
        string[] answer = strings.OrderBy(str => str[n]).ToArray();
        
        return answer;
    }
}