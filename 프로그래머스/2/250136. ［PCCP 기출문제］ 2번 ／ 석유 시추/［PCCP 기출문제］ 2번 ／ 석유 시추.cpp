#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int BFS(vector<vector<int>>& land, vector<vector<bool>>& visited, vector<vector<int>>& oil, int i, int j, int idx)
{
    queue<pair<int,int>> q;
    
    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0};
 
    q.push({i, j});
    visited[i][j] = true;
    oil[i][j] = idx;
    
    int cnt = 1;
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];
            
            if(newY < 0 || newY >= land.size() || newX < 0 || newX >= land[0].size()) continue;
            if(visited[newY][newX]) continue;
            if(land[newY][newX] == 0) continue;
            
            visited[newY][newX] = true;
            oil[newY][newX] = idx;
            cnt++;
            q.push({newY, newX});
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
    vector<vector<int>> oil(land.size(), vector<int>(land[0].size(), 0));
    int idx = 1;
    vector<int> oilCount;
    
    for(int i = 0 ; i < land.size(); i++)
    {
        for(int j = 0; j < land[0].size(); j++)
        {
            if(visited[i][j]) continue;
            if(land[i][j] == 0) continue;
            
            oilCount.push_back(BFS(land, visited, oil, i, j, idx++));
        }
    }
    
    for(int j = 0; j < land[0].size(); j++)
    {
        set<int> currentLine;
        int currentCnt = 0;
        
        for(int i = 0; i < land.size(); i++)
        {
            if(oil[i][j] == 0) continue;
            if(currentLine.count(oil[i][j]) == 0)
            {
                currentLine.insert(oil[i][j]);
                currentCnt += oilCount[oil[i][j] - 1];
            }
        }
        
        answer = max(answer, currentCnt);
    }
    return answer;
}