#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 999'999;

void cut(string s, int size)
{
    vector<string> temp;
    int current = 0;
    bool bcompress = false;
    int iterCnt = 1;
    
    for(int i = 0; i < s.size(); i += size)
    {
        string token = s.substr(i, size);
        
        if(temp.empty())
        {
            current += token.size();
            temp.push_back(token);
            continue;
        }
        
        if(temp.back() == token)
        {
            iterCnt++;
        }
        else
        {
            if(iterCnt != 1)
            {
                current += to_string(iterCnt).size();
            }
            
            current += token.size();
            temp.push_back(token);
            iterCnt = 1;
        }
    }
    
    if(iterCnt != 1)
    {
        current += to_string(iterCnt).size();
    }
    
    cnt = min(cnt, current);
}

int solution(string s) {
    int answer = 0;
    
    if(s.size() == 1) return 1;

    for(int i = 1; i <= s.size()/2; i++)
    {
        cut(s, i);
    }
    
    return cnt;
}