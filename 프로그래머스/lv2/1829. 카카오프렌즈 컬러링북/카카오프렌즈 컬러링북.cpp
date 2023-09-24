#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int startY, int startX, vector<vector<int>>& picture, vector<vector<bool>>& visited, vector<pair<int,int>>& dir)
{
    int m = picture.size();
    int n = picture[0].size();
    int val = picture[startY][startX];
    int cnt = 1;
    
    queue<pair<int,int>> q;
    q.push({startY, startX});
    visited[startY][startX] = true;
    
    while(!q.empty())
    {
        int y = q.front().first; 
        int x = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4; i++)
        {
            int new_y = y + dir[i].first;
            int new_x = x + dir[i].second;
            
            if(new_y < 0 || new_y >= m || new_x < 0 || new_x >= n) continue;
            if(visited[new_y][new_x]) continue;
            if(picture[new_y][new_x] != val) continue;

            visited[new_y][new_x] = true;
            q.push({new_y, new_x});
            
            cnt++;
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(visited[i][j]) continue;
            if(picture[i][j] == 0) continue;
            
            max_size_of_one_area = max(bfs(i, j, picture, visited, dir), max_size_of_one_area);
            number_of_area++;
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}