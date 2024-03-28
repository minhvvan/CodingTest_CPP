#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;


void Dijk(vector<vector<pair<int,int>>>& road, vector<int>& dp, int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    vector<int> visited(dp.size(), false);
    
    vector<int> dist(dp.size(), INT_MAX);
    
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();
                
        if(visited[current]) continue;
        visited[current] = true;
        
        for(auto [next, cost] : road[current])
        {
            if(dist[current]+cost < dist[next])
            {
                dist[next] = dist[current]+cost;
                pq.push({-dist[next], next});
            }
        }
    }
    
    for(int i = 1; i < dp.size(); i++) dp[i] += dist[i];
}

void BFS(vector<vector<pair<int,int>>>& road, vector<int>& dp, int start, int end)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(dp.size(), false);
    pq.push({0, start});
    
    while(!pq.empty())
    {
        auto [sum, current] = pq.top();
        pq.pop();
        
        if(current == end)
        {
            //cout << sum << "\n";
            dp[start] += sum;
            break;
        }
        if(visited[current]) continue;
        visited[current] = true;
        
        for(auto [next, cost] : road[current])
        {
            pq.push({sum+cost, next});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    
    vector<vector<pair<int,int>>> road(n+1);
    vector<int> dp(n+1, 0);
    for(auto& fare : fares)
    {
        road[fare[0]].push_back({fare[1], fare[2]});
        road[fare[1]].push_back({fare[0], fare[2]});
    }
    
    Dijk(road, dp, s);
    Dijk(road, dp, a);
    Dijk(road, dp, b);
    
//     for(int i = 1; i <= n; i++)
//     {
//         if(i != a) 
//         {
//             //cout << "A: ";
//             BFS(road, dp, i, a);
//         }
//         if(i != b)
//         {
//             //cout << "B: "; 
//             BFS(road, dp, i, b);
//         }
        
//         //cout << "Dist: " << dp[i] << "\n\n";
//     }
    
    
    for(auto dist : dp)
    {
        if(dist != 0) answer = min(answer, dist);
    }
    
    return answer;
}