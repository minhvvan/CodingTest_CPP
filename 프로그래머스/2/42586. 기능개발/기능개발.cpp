#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    //진도 100 -> 서비스
    //기능별 속도 다름
    //먼저 개발된 후순위 기능은 전순위가 완성되면 같이 배포
    
    for(int i = 0 ; i < progresses.size(); i++)
    {
        int rest = 100 - progresses[i];
        int day = rest % speeds[i] == 0 ? rest/speeds[i] : rest/speeds[i] + 1;      
        
        if(days.empty()) 
        {
            days.push_back(day);
            continue;
        }
        
        // 10 2 3 4 2
        bool bIsGreater = false;
        for(auto d : days)
        {
            if(d >= day)
            {
                bIsGreater = true;
                break;
            }
        }
        
        if(!bIsGreater)
        {
            int cnt = days.size();
            answer.push_back(cnt);
            days.clear();
        }
        
        days.push_back(day);
    }
    
    answer.push_back(days.size());
    
    return answer;
}