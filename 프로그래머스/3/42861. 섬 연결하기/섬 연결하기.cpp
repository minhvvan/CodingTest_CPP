#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    };
};


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //n개 cost
    //최소비용 연결
    const int MAX = 99999999;
    
    vector<vector<pair<int,int>>> roads(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<bool> visited(n, false);
    
    
    for(auto cost : costs)
    {
        roads[cost[0]].push_back({cost[1], cost[2]});
        roads[cost[1]].push_back({cost[0], cost[2]});
    }
    
    visited[0] = true;
    for(int i = 0; i < roads[0].size(); i++)
    {
        pq.push({roads[0][i].first, roads[0][i].second});
    }
    
    
    while(!pq.empty())    
    {
        auto [idx, cost] = pq.top();
        pq.pop();
        
        if(visited[idx]) continue;
        visited[idx] = true;
        answer += cost;
        
        for(int i = 0; i < roads[idx].size(); i++)
        {
            if(visited[roads[idx][i].first]) continue;
            pq.push({roads[idx][i].first, roads[idx][i].second});
        }
    }
    
    
    return answer;
}