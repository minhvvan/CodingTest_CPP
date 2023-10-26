#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto s : scoville)
    {
        pq.push(s);
    }
    
    while(!pq.empty())
    {
        int small = pq.top();
        pq.pop();
        
        if(small >= K) break;
        
        if(!pq.empty())
        {
            int next = pq.top();
            pq.pop();

            pq.push(small + next*2);
            answer++;
        }
        else
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}