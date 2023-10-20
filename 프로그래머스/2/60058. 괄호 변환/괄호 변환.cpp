#include <string>
#include <vector>
#include <iostream>

using namespace std;


string convert(string p)
{
    if(p.size() == 0) return "";
    
    string u;
    string v;
    {
        int left = 0;
        int right = 0;
        
        u += p[0];
        if(p[0] == '(') left++;
        else right++;
        
        for(int i = 1; i < p.size(); i++)
        {
            if(left == right)
            {
                v += p[i];
            }
            else 
            {
                u += p[i];
                
                if(p[i] == '(') left++;
                else right++;
            }
        }
    }
    
    {
        //올바른 문자열인지 체크
        bool bCorret = true;
        int left = 0;
        int right = 0;
        
        for(auto c : u)
        {
            if(c == '(')
            {
                left++;
            }
            else
            {
                if(left == 0)
                {
                    bCorret = false;
                    break;
                }
                
                left--;
            }
        }
        
        if(!bCorret)
        {
            string temp = "(";
            temp += convert(v);
            temp += ")";
            
            for(int i = 0; i < u.size(); i++)
            {
                if(i == 0 || i == u.size() - 1) continue;
                
                if(u[i] == '(') temp += ')';
                else temp += '(';
            }
            
            u = temp;
        }
        else
        {
            u += convert(v);
        }
    }
    
    return u;
}


string solution(string p) {
    string answer = "";
    
    
    answer = convert(p);
    
    return answer;
}