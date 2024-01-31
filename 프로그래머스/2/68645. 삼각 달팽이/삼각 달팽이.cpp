#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(1'000, vector<int>(1'000, 0));
    
    vector<int> dy = {1, 0, -1};
    vector<int> dx = {0, 1, -1};
    
    int size = 0;
    for(int i = 1; i <= n; i++) size += i;
    
    int cursorY = 0;
    int cursorX = 0;
    int num = 1;
    int dir = 0;
    
    snail[cursorY][cursorX] = num++;
    
    for(int i = 1; i < size; i++)
    {
        cursorY += dy[dir];
        cursorX += dx[dir];
        
        if(cursorX < 0 || cursorX >= n || cursorY < 0 || cursorY >= n)
        {
            cursorY -= dy[dir];
            cursorX -= dx[dir];
            
            dir = (dir + 1) % 3;
            
            cursorY += dy[dir];
            cursorX += dx[dir];
        }
        
        if(snail[cursorY][cursorX] != 0)
        {
            cursorY -= dy[dir];
            cursorX -= dx[dir];
            
            dir = (dir + 1) % 3;
            
            cursorY += dy[dir];
            cursorX += dx[dir];
        }
        
        snail[cursorY][cursorX] = num++;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(snail[i][j] != 0)
            {
                answer.push_back(snail[i][j]);
            }
        }
    }
    
    return answer;
}