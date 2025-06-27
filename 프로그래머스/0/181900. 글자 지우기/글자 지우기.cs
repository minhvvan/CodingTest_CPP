using System;

public class Solution {
    public string solution(string my_string, int[] indices) {
        string answer = "";
        
        Array.Sort(indices);

        int cursor = 0;
        for(int i = 0 ; i < my_string.Length; i++)
        {
            if(cursor >= indices.Length)
            {
                answer += my_string[i];
                continue;
            }
            
            if(i != indices[cursor])
            {
                answer += my_string[i];
            }
            else
            {
                cursor++;
            }
        }
        
        return answer;
    }
}