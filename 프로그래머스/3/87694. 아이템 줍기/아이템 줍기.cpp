#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool IsInner(int x, int y, vector<vector<int>>& rectangle, int n)
{
    bool bResult = false;
    for(int i = 0; i < rectangle.size(); i++)
    {
        if(i == n) continue;
        if((rectangle[i][0]*2 < x && x < rectangle[i][2]*2) && (rectangle[i][1]*2 < y && y < rectangle[i][3]*2))
        {
            bResult = true;
            break;
        }
    }
    
    return bResult;
}

int BFS(vector<vector<int>>& map, int characterX, int characterY, int itemX, int itemY)
{
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    
    queue<pair<int,int>> q;
    q.push({characterY*2, characterX*2});
    visited[characterY*2][characterX*2] = true;
    
    vector<int> dy = {1, 0, -1, 0};
    vector<int> dx = {0, -1, 0, 1};
    
    int result = 0;
    
    while(!q.empty())
    {
        int size = q.size();
        for(int n = 0; n < size; n++)
        {
            auto [y, x] = q.front();
            q.pop();
        
            for(int i = 0; i < 4; i++)
            {
                int new_y = y + dy[i];
                int new_x = x + dx[i];

                if(visited[new_y][new_x]) continue;
                if(map[new_y][new_x] == 0) continue;
                if(new_y == itemY*2 && new_x == itemX*2) return (++result)/2;

                q.push({new_y, new_x});
                visited[new_y][new_x] = true;
            }
        }
        
        result++;
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    const int MAX = 102;
    
    vector<vector<int>> map(MAX, vector<int>(MAX, 0));
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int startX = rectangle[i][0]*2;
        int startY = rectangle[i][1]*2;
        int endX = rectangle[i][2]*2;
        int endY = rectangle[i][3]*2;
        
        for(int x = startX; x <= endX; x++)
        {
            if(!IsInner(x, startY, rectangle, i))
            {
                map[startY][x] = 1;
            }
        }
        
        for(int x = startX; x <= endX; x++)
        {
            if(!IsInner(x, endY, rectangle, i))
            {
                map[endY][x] = 1;
            }
        }
        
        for(int y = startY; y <= endY; y++)
        {
            if(!IsInner(startX, y, rectangle, i))
            {
                map[y][startX] = 1;
            }
        }
        
        for(int y = startY; y <= endY; y++)
        {
            if(!IsInner(endX, y, rectangle, i))
            {
                map[y][endX] = 1;
            }
        }
    }
  
    answer = BFS(map, characterX, characterY, itemX, itemY);
    
    return answer;
}