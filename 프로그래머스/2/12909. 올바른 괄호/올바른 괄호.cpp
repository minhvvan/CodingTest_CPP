#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> brackets;
    
    for(auto bracket : s)
    {
        if(bracket == '(' || brackets.empty())
        {
            brackets.push_back(bracket);
            continue;
        }
        
        if(brackets.back() == '(') brackets.pop_back();
        else
        {
            answer = false;
            break;
        }
    }
    
    if(!brackets.empty()) answer = false;

    return answer;
}