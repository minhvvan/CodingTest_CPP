#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int N;

//dist, idx, cnt
vector<int> BFS(int start)
{
    queue<int> q;
    vector<bool> visited(N+1, false);
    q.push(start);
    visited[start] = true;
    
    int dist = 0;
    int farNode = 0;
    int cnt = 0;
    while(!q.empty())
    {
        cnt = q.size();
        bool bEnd = true;
        for(int i = 0 ; i < cnt; i++)
        {
            int current = q.front();
            q.pop();
            
            for(auto next : adj[current])
            {
                if(visited[next]) continue;
                visited[next] = true;
                
                farNode = next;
                bEnd = false;
                q.push(next);
            }
        }
        
        if(!bEnd) dist++;
    }
    
    return {dist, farNode, cnt};
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    N = n;
    
    adj.resize(n+1);
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    auto result = BFS(1);
    cout << result[0] << " " << result[1] << " " << result[2] << "\n";
    
    int leaf = result[1];
    auto startLeaf = BFS(leaf);
    
    if(startLeaf[2] > 1) answer = startLeaf[0];
    else
    {
        auto last = BFS(startLeaf[1]);
  
        if(last[2] > 1) answer = last[0];
        else answer = last[0] - 1;
    }
    
    return answer;
}