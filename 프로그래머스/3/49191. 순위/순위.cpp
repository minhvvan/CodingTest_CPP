#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void BFS(vector<vector<int>>& edge, vector<vector<bool>>& rel, int start, int n)
{
    queue<int> q;
    
    q.push(start);
    vector<bool> visited(n+1, false);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto next : edge[cur])
        {
            if(visited[next]) continue;
                
            visited[next] = true;
            rel[start][next] = true;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> rank(n+1, 0);
    
    vector<vector<bool>> rel(n+1, vector(n+1, false));
    vector<vector<int>> edge(n+1);
    
    for(auto result : results)
    {
        rel[result[0]][result[1]] = true;
        edge[result[0]].push_back(result[1]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        BFS(edge, rel, i, n);
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        rel[i][i] = true;
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        for(int j = 1; j <= n; j++)
        {
            if(!rel[i][j])
            {
                if(!rel[j][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
        {
            answer++;
        }
    }
    
    return answer;
}