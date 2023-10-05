#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int Search(string name)
{
    string temp;
    for(auto n : name)
    {
        temp += "A";
    }
    
    if(temp == name) return 0;
    
    queue<tuple<string, int, int>> q;
    q.push({temp, 0, 0});

    while(!q.empty())
    {
        auto[str, cnt, cursor] = q.front();
        q.pop();
        
        int move = min(name[cursor] - str[cursor], 'Z' - name[cursor] + 1);
        str[cursor] = name[cursor];
        
        cnt += move;
        
        if(str == name)
        {
            return cnt;
        }
        
        q.push({str, cnt+1, (cursor+1)%name.size()});
        q.push({str, cnt+1, (cursor-1+name.size())%name.size()});
    }
    
    return 0;
}

int solution(string name) {
    int answer = 0;
    
    answer = Search(name);
    
    return answer;
}