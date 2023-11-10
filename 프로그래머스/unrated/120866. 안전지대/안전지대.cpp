#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    vector<vector<bool>> safe(board.size(), vector<bool>(board[0].size(), true));
    answer = board.size() * board[0].size();
    
    vector<int> dy = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1)
            {
                if(safe[i][j])
                {
                    answer--;
                }
                safe[i][j] = false;
                
                for(int k = 0; k < 8; k++)
                {
                    int new_y = i + dy[k];
                    int new_x = j + dx[k];
                    
                    if(new_y < 0 || new_y >= board.size() || new_x < 0 || new_x >= board[0].size()) continue;
                    
                    if(safe[new_y][new_x] == true) answer--;
                    safe[new_y][new_x] = false;
                }
            }
        }
    }
    
    return answer;
}