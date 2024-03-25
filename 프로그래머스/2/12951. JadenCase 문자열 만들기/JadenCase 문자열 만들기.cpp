#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool bFirst = true;
    for(char c : s)
    {
        if(c == ' ') 
        {
            answer += tolower(c);
            bFirst = true;
            continue;
        }
        
        if(bFirst)
        {
            bFirst = false;
            if(c - '0' >= 0 && c - '0' <= 9) answer += c;
            else answer += toupper(c);
        }
        else
        {
            answer += tolower(c);
        }
    }
    
    return answer;
}