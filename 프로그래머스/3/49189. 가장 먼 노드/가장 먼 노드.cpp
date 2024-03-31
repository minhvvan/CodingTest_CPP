#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

void BFS(vector<vector<int>>& roads, map<int,int>& dp)
{
    vector<bool> visited(roads.size(), false);
    queue<pair<int,int>> q;
    
    q.push({1, 0});
    
    while(!q.empty())
    {
        auto [current, dist] = q.front();
        q.pop();
        
        if(visited[current]) continue;
        visited[current] = true;
        
        dp[dist]++;
        for(int next : roads[current])
        {
            if(visited[next]) continue;
            q.push({next, dist+1});
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    map<int,int> dp;
    vector<vector<int>> roads(n+1);
    
    for(auto& e : edge)
    {
        roads[e[0]].push_back(e[1]);
        roads[e[1]].push_back(e[0]);
    }
    
    BFS(roads, dp);
    
    answer = (--dp.end())->second;
    
    return answer;
}