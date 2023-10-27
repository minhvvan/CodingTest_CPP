#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int Bfs(vector<vector<int>>& maps, vector<vector<bool>>& visited)
{
    int cnt = 1;
    
    queue<pair<int,int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};
    
    while(!q.empty())
    {
        int size = q.size();
        
        for(int k = 0; k < size; k++)
        {
            auto [y, x] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int new_y = y + dy[i];
                int new_x = x + dx[i];
                
                if(new_y < 0 || new_y >= maps.size() || new_x < 0 || new_x >= maps[0].size()) continue;
                if(maps[new_y][new_x] == 0) continue;
                if(visited[new_y][new_x]) continue;
                
                if(new_y == maps.size()-1 && new_x == maps[0].size()-1) return cnt+1;
                
                visited[new_y][new_x] = true;
                q.push({new_y, new_x});
            }
        }
        
        cnt++;
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    answer = Bfs(maps, visited);    
    
    return answer;
}