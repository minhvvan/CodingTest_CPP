#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    vector<int> dy = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0};
    
    for(int i = 0 ; i < 4; i++)
    {
        int newY = h + dy[i];
        int newX = w + dx[i];
        
        if(newY < 0 || newY >= board.size() || newX < 0 || newY >= board[0].size()) continue;
        
        if(board[newY][newX] == board[h][w]) answer++;
    }
    
    return answer;
}