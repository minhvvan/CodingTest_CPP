#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //queue에서 꺼내기
    //우선순위가 더 높은게 있다면 꺼낸거 다시 넣기
    //없으면 실행
    
    //{idx, priority}
    queue<pair<int,int>> processes;
    for(int i = 0 ; i < priorities.size(); i++)
    {
        processes.push({i, priorities[i]});
    }
    
    while(!processes.empty())
    {
        auto [idx, priority] = processes.front();
        processes.pop();
        
        bool bIsBigger = false;
        for(int i = 0; i < processes.size(); i++)
        {
            auto [tempIdx, tempPriority] = processes.front();                        
            processes.pop();
            
            if(priority < tempPriority) bIsBigger = true;
            
            processes.push({tempIdx, tempPriority});
        }
        
        if(bIsBigger) processes.push({idx, priority});
        else
        {
            answer++;
            if(idx == location) break;
        }
    }
    
    return answer;
}