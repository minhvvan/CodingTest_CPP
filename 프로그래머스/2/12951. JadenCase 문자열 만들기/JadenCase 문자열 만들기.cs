using System;

public class Solution {
    public string solution(string s) {
        string answer = "";
        
        bool isFirst = true;
        for(int i = 0; i < s.Length; i++)
        {
            if(s[i] == ' ')
            {
                isFirst = true;
                answer += s[i];
                continue;
            }
            
            if(isFirst)
            {
                isFirst = false;
                var c = s[i];
                if(!('0' <= c && c <= '9'))
                {
                    c = char.ToUpper(c);
                }
                
                answer += c;
                continue;
            }
                      
            answer += char.ToLower(s[i]);
        }
        
        return answer;
    }
}