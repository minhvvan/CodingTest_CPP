#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto skillTree: skill_trees)
    {
        bool bPossible = true;
        int lastIdx = -1;
        
        for(auto s : skillTree)
        {
            int idx = skill.find(s);
            if(idx == string::npos) continue;
            
            if(lastIdx == -1 && idx != 0)
            {
                bPossible = false;
                break;
            }
            
            if(idx < lastIdx || lastIdx + 1 < idx)
            {
                bPossible = false;
                break;
            }
            
            lastIdx = idx;
        }
        
        if(bPossible) answer++;
    }
    
    return answer;
}