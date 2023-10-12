#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, -1, 0, 1};

int cnt = 999'999;
int limit = 999;

void Print(vector<vector<int>>& board)
{
    for(auto row : board)
    {
        for(auto cell : row)
        {
            cout << cell << " ";
        }
        
        cout << "\n";
    }
    
    cout << "\n";
}


int FindTarget(vector<vector<int>>& board, int r, int c, int target_y, int target_x)
{
    if(r == target_y && c == target_x) return 0;
    
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(board.size(), vector<bool>(board.size(), false));
    
    q.push({r, c});
    visited[r][c] = true;
    
    int move = 0;
    bool endFlag = false;
    
    while(!q.empty())
    {
        int size = q.size();
        for(int t = 0; t < size; t++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
        
            //1칸
            for(int i = 0; i < 4; i++)
            {
                int new_y = y + dy[i];
                int new_x = x + dx[i];
                
                if(new_y < 0 || new_y >= 4 || new_x < 0 || new_x >= 4) continue;
                if(visited[new_y][new_x]) continue;
                
                if(new_y == target_y && new_x == target_x)
                {
                    endFlag= true;
                    break;
                }
                
                visited[new_y][new_x] = true;
                q.push({new_y, new_x});
            }
            
            //ctrl+
            for(int i = 0; i < 4; i++)
            {
                int new_y = y + dy[i];
                int new_x = x + dx[i];
                
                if(new_y < 0 || new_y >= 4 || new_x < 0 || new_x >= 4) continue;

                while(board[new_y][new_x] == 0)
                {
                    new_y += dy[i];
                    new_x += dx[i];
                    
                    if(new_y < 0 || new_y >= 4 || new_x < 0 || new_x >= 4)
                    {
                        new_y -= dy[i];
                        new_x -= dx[i];
                        
                        break;
                    }
                }
                
                if(visited[new_y][new_x]) continue;
                
                if(new_y == target_y && new_x == target_x)
                {
                    endFlag= true; 
                    break;
                }
                
                visited[new_y][new_x] = true;
                q.push({new_y, new_x});
            }
                
            if(endFlag) break;
        }
        
        move++;
        if(endFlag) break;
    }
    
    return move;
}


void DFS(vector<vector<int>>& board, vector<bool>& checked, vector<vector<pair<int,int>>>& coords, int r, int c, int depth, int move, vector<pair<int,int>>& process)
{
    if(depth == limit)
    {
        cnt = min(cnt, move);
        
//         for(auto p : process)
//         {
//             cout << p.first << "," << p.second << "\n"; 
//         }
//         cout << "move: " << move << "\n";
        
//         cout << "--------------\n";
        return;
    }
    
    for(int i = 1; i <= limit; i++)
    {
        if(checked[i]) continue;
        
        checked[i] = true;
        {
            int temp = 0;
        
            //0->1
            temp += FindTarget(board, r, c, coords[i][0].first, coords[i][0].second);
            board[coords[i][0].first][coords[i][0].second] = 0;
            
            int temp2 = FindTarget(board, coords[i][0].first, coords[i][0].second, coords[i][1].first, coords[i][1].second);
            temp += temp2;
            board[coords[i][1].first][coords[i][1].second] = 0;
            
            process.push_back({coords[i][0].first, coords[i][0].second});
            process.push_back({coords[i][1].first, coords[i][1].second});
            
            DFS(board, checked, coords, coords[i][1].first, coords[i][1].second, depth+1, move+temp+2, process);
            
            board[coords[i][0].first][coords[i][0].second] = i;
            board[coords[i][1].first][coords[i][1].second] = i;
            
            process.pop_back();
            process.pop_back();
        }

        
        //1->0
        {
            int temp = 0;
        
            //0->1
            temp += FindTarget(board, r, c, coords[i][1].first, coords[i][1].second);
            board[coords[i][1].first][coords[i][1].second] = 0;
            
            temp += FindTarget(board, coords[i][1].first, coords[i][1].second, coords[i][0].first, coords[i][0].second);
            board[coords[i][0].first][coords[i][0].second] = 0;
            
            process.push_back({coords[i][1].first, coords[i][1].second});
            process.push_back({coords[i][0].first, coords[i][0].second});
            
            DFS(board, checked, coords, coords[i][0].first, coords[i][0].second, depth+1, move+temp+2, process);
            
            board[coords[i][0].first][coords[i][0].second] = i;
            board[coords[i][1].first][coords[i][1].second] = i;
            
            process.pop_back();
            process.pop_back();
        }
        
        checked[i] = false;
    }
}


int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;

    vector<vector<pair<int,int>>> coords(7);
    
    int temp = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0 ; j < board[0].size(); j++)
        {
            if(board[i][j] != 0)
            {
                coords[board[i][j]].push_back({i, j});
            }
            
            temp = max(temp, board[i][j]);
        }
    }
    
    limit = temp;
    vector<bool> visited(limit+1, false);
    vector<pair<int, int>> p;
    
    DFS(board, visited, coords, r, c, 0, 0, p);
    
    return cnt;
}