#include <string>
#include <vector>
#include <deque>

using namespace std;

bool CheckCorrect(deque<char>& bracket)
{
    vector<char> temp;
    
    for(auto c: bracket)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            temp.push_back(c);
        }
        else
        {
            if(temp.size() == 0) return false;
            
            if(c == ')')
            {
                if(temp.back() != '(') return false;
                else temp.pop_back();
            }
            
            if(c == ']')
            {
                if(temp.back() != '[') return false;
                else temp.pop_back();
            }
            
            if(c == '}')
            {
                if(temp.back() != '{') return false;
                else temp.pop_back();
            }
        }
    }
    
    if(temp.size() == 0) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    deque<char> bracket;
    for(auto c : s)
    {
        bracket.push_back(c);
    }
    
    //check
    for(int i = 0; i < bracket.size(); i++)
    {
        if(CheckCorrect(bracket)) answer++;
        
        //rotate
        char c = bracket.front();
        bracket.pop_front();
        
        bracket.push_back(c);
    }
    
    return answer;
}