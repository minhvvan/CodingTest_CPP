#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b) {
        return get<2>(a) > get<2>(b);
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> roads(N+1);
    
    for(auto r : road)
    {
        roads[r[0]].push_back({r[1], r[2]});
        roads[r[1]].push_back({r[0], r[2]});
    }
    
    //다익스트라
    vector<int> costs(N+1, 500'001);
    vector<bool> visited(N+1, false);
    costs[1] = 0;
    
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> pq;
    for(auto r : roads[1])
    {
        pq.push({1, r.first, r.second});
    }
    
    while(!pq.empty())
    {
        auto [from, to, cost] = pq.top();
        pq.pop();
        
        costs[to] = min(costs[to], costs[from]+cost);
        
        for(auto r : roads[to])
        {
            if(costs[r.first] <= costs[to]+r.second) continue;
            pq.push({to, r.first, r.second});
        }
    }
    
    for(auto c : costs)
    {
        if(c <= K) answer++;
    }

    return answer;
}