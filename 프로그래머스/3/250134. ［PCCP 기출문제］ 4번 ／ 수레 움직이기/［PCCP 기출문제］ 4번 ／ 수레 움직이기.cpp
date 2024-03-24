#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum
{
    BLANK,
    REDSTART,
    BLUESTART,
    REDEND,
    BLUEEND,
    WALL
};

const int MAX = 999'999'999;

int DFS(vector<vector<int>>& maze, pair<int,int> redCart, pair<int,int>blueCart, pair<int,int>& redGoal, pair<int,int>& blueGoal, 
         vector<vector<bool>>& redVisited, vector<vector<bool>>& blueVisited, int depth)
{
    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0};

    int result = MAX;
    
    for(int i = 0; i < 4; i++)
    {
        //move red
        int newRedY;
        int newRedX;
        
        bool bRedArrive = false;
        
        if(redCart.first == redGoal.first && redCart.second == redGoal.second)
        {
            newRedY = redGoal.first;
            newRedX = redGoal.second;
            bRedArrive = true;
        }
        else
        {
            newRedY = redCart.first + dy[i];
            newRedX = redCart.second + dx[i];
        }
        
        if(newRedY < 0 || newRedY >= maze.size() || newRedX < 0 || newRedX >= maze[0].size()) continue;
        if(maze[newRedY][newRedX] == WALL) continue;
        if(redVisited[newRedY][newRedX] && !bRedArrive) continue;
        
        for(int j = 0; j < 4; j++)
        {
            //move blue
            
            int newBlueY;
            int newBlueX;       
            
            bool bBlueArrive = false;
        
            if(blueCart.first == blueGoal.first && blueCart.second == blueGoal.second)
            {
                newBlueY = blueGoal.first;
                newBlueX = blueGoal.second;
                bBlueArrive = true;
            }
            else
            {
                newBlueY = blueCart.first + dy[j];
                newBlueX = blueCart.second + dx[j];
            }
            
            if(newBlueY < 0 || newBlueY >= maze.size() || newBlueX < 0 || newBlueX >= maze[0].size()) continue;
            if(maze[newBlueY][newBlueX] == WALL) continue;
            if(blueVisited[newBlueY][newBlueX] && !bBlueArrive) continue;
            
            if(newRedY == newBlueY && newRedX == newBlueX) continue;
            if(newRedY == blueCart.first && newRedX == blueCart.second && newBlueY == redCart.first && newBlueX == redCart.second) continue;
            
            
            if(newRedY == redGoal.first && newRedX == redGoal.second && newBlueY == blueGoal.first && newBlueX == blueGoal.second)
            {
                //end
                return depth + 1;
            }
            
            redVisited[newRedY][newRedX] = true;
            blueVisited[newBlueY][newBlueX] = true;
            result = min(result, DFS(maze, {newRedY, newRedX}, {newBlueY, newBlueX}, redGoal, blueGoal, redVisited, blueVisited, depth+1));
            
            redVisited[newRedY][newRedX] = false;
            blueVisited[newBlueY][newBlueX] = false;
        }
    }
    
    return result;
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    pair<int, int> redCart;
    pair<int, int> blueCart;
    
    pair<int, int> redGoal;
    pair<int, int> blueGoal;
    
    for(int i = 0; i < maze.size(); i++)
    {
        for(int j = 0; j < maze[0].size(); j++)
        {
            if(maze[i][j] == REDSTART) redCart = {i, j};
            if(maze[i][j] == BLUESTART) blueCart = {i, j};
            if(maze[i][j] == REDEND) redGoal = {i, j};
            if(maze[i][j] == BLUEEND) blueGoal = {i, j};
        }
    }
    

    vector<vector<bool>> redVisited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<vector<bool>> blueVisited(maze.size(), vector<bool>(maze[0].size(), false));
    
    redVisited[redCart.first][redCart.second] = true;
    blueVisited[blueCart.first][blueCart.second] = true;
    
    answer = DFS(maze, redCart, blueCart, redGoal, blueGoal, redVisited, blueVisited, 0);
    
    return answer == MAX ? 0 : answer;
}