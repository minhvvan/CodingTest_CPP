#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(auto work : works) pq.push(work);
    
    for(int i = 0 ; i < n; i++)
    {
        int work = pq.top();
        pq.pop();
        work--;
        pq.push(work);
    }
    
    while(!pq.empty())
    {
        int work = pq.top();
        pq.pop();
        
        if(work < 0) continue;
        answer += work*work;
    }
    
    return answer;
}