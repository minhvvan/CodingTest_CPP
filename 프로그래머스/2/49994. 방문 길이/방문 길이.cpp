#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Move(string dirs)
{
    int answer = 0;
    
    vector<int> dy = {-1, 0, 0, 1};
    vector<int> dx = {0, 1, -1, 0};
    
    vector<vector<vector<int>>> moves(11, vector<vector<int>>(11));
    
    int y = 5;
    int x = 5;
    
    for(auto dir : dirs)
    {
        int i = -1;
        switch(dir)
        {
        case 'U':
            i = 0;
            break;
        case 'D':
            i = 3;
            break;
        case 'R':
            i = 1;
            break;
        case 'L':
            i = 2;
            break;
        }
        
        int new_y = y + dy[i];
        int new_x = x + dx[i];
        
        if(new_y < 0 || new_y >= 11 || new_x < 0 || new_x >= 11) continue;
        
        auto it = find(moves[new_y][new_x].begin(), moves[new_y][new_x].end(), i);
        if(it == moves[new_y][new_x].end())
        {
            answer++;
            
            moves[new_y][new_x].push_back(i);
            moves[y][x].push_back(3-i);
        }
        
        y = new_y;
        x = new_x;
    }
    
    return answer;
}

int solution(string dirs) {
    int answer = 0;
    
    answer = Move(dirs);
    
    return answer;
}