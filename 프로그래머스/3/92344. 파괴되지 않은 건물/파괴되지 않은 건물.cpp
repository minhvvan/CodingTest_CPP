#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum SkillType
{
    ATTACK = 1,
    HEAL = 2
};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> diff(board.size()+1, vector<int>(board[0].size()+1, 0));
    
    for(auto s : skill)
    {
        int d;
        if(s[0] == ATTACK) d = s[5] * -1;
        else d = s[5];
        
        diff[s[1]][s[2]] += d;
        diff[s[3] + 1][s[4] + 1] += d;
        diff[s[1]][s[4] + 1] -= d;
        diff[s[3] + 1][s[2]] -= d;
    }
    
    for (int i = 0; i <= board.size(); i++) 
    {
        for (int j = 0; j < board[0].size(); j++) 
        {
            diff[i][j + 1] += diff[i][j];
        }
    }
 
    for (int j = 0; j <= board[0].size(); j++) 
    {
        for (int i = 0; i < board.size(); i++) 
        {
            diff[i + 1][j] += diff[i][j];
        }
    }
    
    
    for (int i = 0; i <board.size(); i++) 
    {
        for (int j = 0; j < board[0].size(); j++) 
        {
            if (board[i][j] + diff[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}