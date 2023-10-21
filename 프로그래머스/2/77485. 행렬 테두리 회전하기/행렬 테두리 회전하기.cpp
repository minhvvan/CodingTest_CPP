#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Rotate(vector<vector<int>>& board, vector<int>& query)
{
    int minVal = 999'999;
    
    int up = query[0] - 1;
    int left = query[1] - 1;
    int down = query[2] - 1;
    int right = query[3] - 1;
    
    // ->
    int stored = board[up][right];
    minVal = min(minVal, stored);
    for(int i = right; i > left; i--)
    {
        board[up][i] = board[up][i-1];
        minVal = min(minVal, board[up][i]);
    }
    
    // down
    int stored2 = board[down][right];    
    minVal = min(minVal, stored2);
    for(int i = down; i > up+1; i--)
    {
        board[i][right] = board[i-1][right];
        minVal = min(minVal, board[i][right]);
    }
    board[up+1][right] = stored;
    
    
    //<-
    stored = board[down][left];
    minVal = min(minVal, stored);
    for(int i = left; i < right-1; i++)
    {
        board[down][i] = board[down][i+1];
        minVal = min(minVal, board[down][i]);
    }
    board[down][right-1] = stored2;
    
    //up
    for(int i = up; i < down-1; i++)
    {
        board[i][left] = board[i+1][left];
        minVal = min(minVal, board[i][left]);
    }
    board[down-1][left] = stored;
    
    
//     for(auto row : board)
//     {
//         for(auto cell : row)
//         {
//             cout << cell << " ";
//         }
//         cout << "\n";
//     }
    
//     cout << "\n";
    
    return minVal;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> board(rows);
    int num = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            board[i].push_back(num++);
        }
    }
    
    for(auto query : queries)
    {
        answer.push_back(Rotate(board, query));
    }
    
    return answer;
}