#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1;
    int maxVal = 0;
    vector<vector<int>> count(board.size(), vector<int>(board[0].size(), 0));

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0 ; j < board[0].size(); j++)
        {
            if(i==0 || j==0 || board[i][j] == 0)
            {
                if(board[i][j])
                {
                    count[i][j] = 1;
                    maxVal = max(maxVal, 1);
                }
                continue;
            }
            
            int temp = min(count[i-1][j], count[i][j-1]);
            temp = min(temp, count[i-1][j-1]) + 1;
            
            count[i][j] = temp;
            maxVal = max(maxVal, temp);
        }
    }

    answer = maxVal*maxVal;
    return answer;
}