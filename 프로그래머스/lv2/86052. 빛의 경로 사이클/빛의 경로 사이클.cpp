#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int Cycle(int startI, int startJ, int startDir, vector<vector<int>>& Dir, vector<string>& grid, vector<vector<bool>>& visited)
{
    int cnt = 1;
    int currentI = startI;
    int currentJ = startJ;
    int currentDir = startDir;
    
    visited[startI * grid[0].size() + startJ][startDir] = true;
    
    while(true)
    {
        currentI = (currentI + Dir[currentDir][0] + grid.size()) % grid.size();
        currentJ = (currentJ + Dir[currentDir][1] + grid[0].size()) % grid[0].size();
        
        if(grid[currentI][currentJ] == 'L')
        {
            currentDir = (currentDir - 1 + 4) % 4;
        }
        else if(grid[currentI][currentJ] == 'R')
        {
            currentDir = (currentDir+1) % 4;
        }
        
        if(visited[currentI * grid[0].size() + currentJ][currentDir]) break;
        
        visited[currentI * grid[0].size() + currentJ][currentDir] = true;
        cnt++;
    }
    
    return cnt;
}


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    vector<vector<bool>> visited(grid.size() * grid[0].size(), vector<bool>(4, false));

    // 4방향
    vector<vector<int>> Dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            for(int k = 0 ; k < 4; k++)
            {
                if(visited[i * grid[0].size() + j][k] == true) continue;
                int temp = Cycle(i, j, k, Dir, grid, visited);
                answer.push_back(temp);
                
                //cout << "i: " << i << " j: " << j << " dir: " << k <<" cnt: "<< temp << "\n";
            }
        }
    }

    
    sort(answer.begin(), answer.end());
    
    return answer;
}