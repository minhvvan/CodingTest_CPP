using System;

public class Solution {
    public string solution(string s, int n) {
        string answer = "";
        
        //0~26 = a~z
        //27~42 = A~Z
        
        foreach(var c in s)
        {
            if('a' <= c && c <= 'z')
            {
                int temp = (c - 'a' + n) % 26;
                answer += (char)(temp + 'a');
            }
            else if('A' <= c && c <= 'Z')
            {
                int temp = (c - 'A' + n) % 26;
                answer += (char)(temp + 'A');
            }
            else
            {
                answer += c;
            }
        }
        
        return answer;
    }
}