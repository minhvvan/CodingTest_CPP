#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

bool Bfs(vector<string>& place, int y, int x)
{
    queue<tuple<int,int,bool>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    
    q.push({y, x, false});
    int depth = 0;
    
    while(!q.empty() && depth < 2)
    {
        int size = q.size();
        for(int t = 0; t < size; t++)
        {
            auto [current_y, current_x, flag] = q.front();
            q.pop();
            
            visited[current_y][current_x] = true;
            
            for(int i = 0; i < 4; i++)
            {
                int new_y = current_y + dy[i];
                int new_x = current_x + dx[i];

                if(new_y < 0 || new_y >= 5 || new_x < 0 || new_x >= 5) continue;
                if(visited[new_y][new_x]) continue;
                
                if(place[new_y][new_x] == 'P') 
                {
                    if(flag) continue;
                    else return false;
                }
                
                if(place[new_y][new_x] == 'O')
                {
                    q.push({new_y, new_x, flag|false});
                }
                else
                {
                    q.push({new_y, new_x, true});
                }
            }
        }
        depth++;
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place : places)
    {
        bool flag = true;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(place[i][j] == 'P')
                {
                    if(!Bfs(place, i, j))
                    {
                        answer.push_back(0);
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) answer.push_back(1);
    }
    
    return answer;
}