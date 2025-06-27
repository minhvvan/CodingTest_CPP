using System.Collections.Generic;

public class Solution {
    public string solution(string s) {
        string answer = "";
        char[] chars = s.ToCharArray(); 
        
        bool isFirst = true;
        int idx = 0;
        for(int i = 0 ; i < chars.Length; i++)
        {
            if(chars[i] == ' ')
            {
                idx = 0;
                continue;
            }
            
            if(idx % 2 == 0)
            {
                chars[i] = char.ToUpper(chars[i]);
            }
            else
            {
                chars[i] = char.ToLower(chars[i]);
            }
            
            idx++;
        }
        
        return new string(chars);
    }
}