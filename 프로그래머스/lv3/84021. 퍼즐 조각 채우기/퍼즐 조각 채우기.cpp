#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

void Print(vector<vector<int>>& blank, vector<vector<int>>& block)
{
    cout << "blank:\n";
    
    for(auto b: blank)
    {
        cout << b[0] << b[1] << "\n";
    }
    cout << "\n";
    
    cout << "block:\n";
    for(auto b: block)
    {
        cout << b[0] << b[1] << "\n";
    }
    cout << "\n";
}

vector<vector<int>> Rotate(vector<vector<int>>& origin, int n)
{
    int minY = n;
    int minX = n;
    vector<vector<int>> result;
    
    for(auto block : origin)
    {
        minY = min(minY, block[1]);
        minX = min(minX, n-1-block[0]);
        result.push_back({block[1], n-1-block[0]});
    }
    
    
//     switch(rot)
//     {
//         case 0:
//             result = origin;
//             break;
            
//         case 90:
//             //i=j, j=n-1-i
//             for(auto block : origin)
//             {
//                 minY = min(minY, block[1]);
//                 minX = min(minX, n-1-block[0]);
//                 result.push_back({block[1], n-1-block[0]});
//             }
            
//             break;
//         case 180:
//             //i=n-1-i, j=n-1-j
//             for(auto block : origin)
//             {
//                 minY = min(minY, n-1-block[0]);
//                 minX = min(minX, n-1-block[1]);
//                 result.push_back({n-1-block[0], n-1-block[1]});
//             }
            
//             break;         
//         case 270:
//             //i=n-1-j, j=i
//             for(auto block : origin)
//             {
//                 minY = min(minY, n-1-block[1]);
//                 minX = min(minX, block[0]);
//                 result.push_back({n-1-block[1], block[0]});
//             }
//             break;         
//     }
    
    for(int i = 0; i < result.size(); i++)
    {
        result[i][0] -= minY;
        result[i][1] -= minX;
    }
    
    sort(result.begin(), result.end(), cmp);
    return result;
}

vector<vector<int>> Bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int y, int x, int num)
{
    vector<vector<int>> result;
    
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = true;
    result.push_back({y, x});
    
    int minY = board.size();
    int minX = board.size();
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        minY = min(minY, y);
        minX = min(minX, x);
        
        for(int i = 0; i < 4; i++)
        {
            int new_y = y + dy[i];
            int new_x = x + dx[i];
            
            if(new_y < 0 || new_y >= board.size() || new_x < 0 || new_x >= board.size()) continue;
            if(visited[new_y][new_x]) continue;        
            if(board[new_y][new_x] != num) continue;        
            
            result.push_back({new_y, new_x});
            q.push({new_y, new_x});
            visited[new_y][new_x] = true;
        }
    }
    
    for(int i = 0; i < result.size(); i++)
    {
        result[i][0] -= minY;
        result[i][1] -= minX;
    }
    
    sort(result.begin(), result.end(), cmp);
    
    return result;
}

pair<bool, int> Match(vector<vector<int>>& blank, vector<vector<int>>& block, int n)
{
    if(blank.size() != block.size()) return {false, 0};
    
    vector<vector<int>> temp = block;
    
    for(int r = 0; r < 4; r++)
    {
        bool flag = true;
        
        if(r != 0)
        {
            temp = Rotate(temp, n);
        }
        
        for(int i = 0; i < blank.size(); i++)
        {
            if(blank[i][0] != temp[i][0] || blank[i][1] != temp[i][1]) 
            {
                flag = false;
                break;
            }
        }
        
        if(flag) 
        {
            return {true, block.size()};
        }
    }
    
    return {false, 0};
}


int fillBlank(vector<vector<vector<int>>>& blanks, vector<vector<vector<int>>>& blocks, int n)
{
    int result = 0;
    vector<bool> usedBlck(blocks.size(), false);
    
    for(int i = 0; i < blanks.size(); i++)
    {
        for(int j = 0; j < blocks.size(); j++)
        {
            if(usedBlck[j]) continue;
            
            auto [bMatch, cnt] = Match(blanks[i], blocks[j], n);
            if(bMatch)
            {
                usedBlck[j] = true;
                
                result += cnt;
                break;
            }
        }
    }
    
    return result;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    
    vector<vector<vector<int>>> blanks;
    vector<vector<vector<int>>> blocks;
    
    vector<vector<bool>> blankVisited(game_board.size(), vector<bool>(game_board.size(), false));
    vector<vector<bool>> blockVisited(game_board.size(), vector<bool>(game_board.size(), false));
    
    for(int i = 0; i < game_board.size(); i++)
    {
        for(int j = 0; j < game_board.size(); j++)
        {
            if(game_board[i][j] == 0 && !blankVisited[i][j])
            {
                auto blank = Bfs(game_board, blankVisited, i, j, 0);
                
                blanks.push_back(blank);
            }
            
            if(table[i][j] == 1 && !blockVisited[i][j])
            {
                auto block = Bfs(table, blockVisited, i, j, 1);
                
                blocks.push_back(block);
            }
        }
    }
    
    answer = fillBlank(blanks, blocks, table.size());
    
    return answer;
}