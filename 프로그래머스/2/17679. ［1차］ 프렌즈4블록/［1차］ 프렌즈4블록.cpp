#include <string>
#include <vector>
#include <iostream>

using namespace std;
int Check(int m, int n, vector<string>& board, vector<vector<bool>>& checked);


int Remove(int m, int n, vector<string>& board, vector<vector<bool>>& checked)
{
    int answer = 0;
    
    //remove
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(checked[i][j])
            {
                answer++;
                checked[i][j] = false;
                board[i][j] = ' ';
            }
        }
    }
    
    //move
    for(int i = m-1; i >= 0; i--)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(board[i][j] == ' ')
            {
                int offset = 0;
                for(int k = i; k >= 0; k--)
                {
                    if(board[k][j] == ' ') offset++;
                    else 
                    {
                        board[k+offset][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }
    }
    
//     for(auto row : board)
//     {
//         for(auto c : row)
//         {
//             cout << c << " ";
//         }
//         cout << "\n";
//     }
    
//     cout << "\n";
    //check
    answer += Check(m, n, board, checked);
    return answer;
}

int Check(int m, int n, vector<string>& board, vector<vector<bool>>& checked)
{
    int cnt = 0;
    
    for(int i = 0; i < m-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            //search(왼쪽 위가 기준)
            if(board[i][j] == ' ') continue;
            if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1])
            {
                checked[i][j] = true;
                checked[i][j+1] = true;
                checked[i+1][j] = true;
                checked[i+1][j+1] = true;
                
                cnt++;
            }
        }
    }
    
    if(cnt == 0) return 0;
    return Remove(m, n, board, checked);
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<bool>> checked(m, vector<bool>(n, false));
    
    answer = Check(m, n, board, checked);


    return answer;
}