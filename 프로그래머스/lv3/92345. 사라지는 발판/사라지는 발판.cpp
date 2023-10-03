#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, -1, 0, 1};

pair<bool, int> moveA(vector<vector<int>> board, vector<int>& aloc, vector<int>& bloc);
pair<bool, int> moveB(vector<vector<int>> board, vector<int>& aloc, vector<int>& bloc);

pair<bool, int> moveA(vector<vector<int>> board, vector<int>& aloc, vector<int>& bloc)
{
    bool bWin = false;
    bool bMove = false;
    int maxCnt = 0;
    int minCnt = 999;
    
    for(int i = 0; i < 4; i++)
    {
        int aY = aloc[0] + dy[i];
        int aX = aloc[1] + dx[i];
        
        if(aY < 0 || aY >= board.size() || aX < 0 || aX >= board[0].size()) continue;
        if(board[aY][aX] == 0) continue;
        
        if(aloc[0] == bloc[0] && aloc[1] == bloc[1])
        {
            //A가 움직여서 이김
            return {false, 1};
        }
        bMove = true;
        
        board[aloc[0]][aloc[1]] = 0;
        vector<int> tempA = {aY, aX};
        
        auto [winTemp, cnt] = moveB(board, tempA, bloc);
        
        if(winTemp)
        {
            //A Win
            bWin = true;
            minCnt = min(cnt+1, minCnt);
        }
        else
        {
            maxCnt = max(cnt+1, maxCnt);
        }
    }
    
    if(!bMove)
    {
        return {true, 0};
    }
    
    if(bWin)
    {
        return {false, minCnt};
    }
    
    //무조건 짐
    return {true, maxCnt};
}

pair<bool, int> moveB(vector<vector<int>> board, vector<int>& aloc, vector<int>& bloc)
{
    bool bWin = false;
    bool bMove = false;
    int maxCnt = 0;
    int minCnt = 999;
    
    for(int i = 0; i < 4; i++)
    {
        int bY = bloc[0] + dy[i];
        int bX = bloc[1] + dx[i];
        
        if(bY < 0 || bY >= board.size() || bX < 0 || bX >= board[0].size()) continue;
        if(board[bY][bX] == 0) continue;

        if(aloc[0] == bloc[0] && aloc[1] == bloc[1])
        {
            //B가 움직여서 이김
            return {false, 1};
        }
        
        bMove = true;
        
        board[bloc[0]][bloc[1]] = 0;
        vector<int> tempB = {bY, bX};
        
        auto [winTemp, cnt] = moveA(board, aloc, tempB);
        
        if(winTemp)
        {
            //B Win
            bWin = true;
            minCnt = min(cnt+1, minCnt);
        }
        else
        {
            maxCnt = max(cnt+1, maxCnt);
        }
    }
    
    if(!bMove)
    {
        return {true, 0};
    }
    
    if(bWin)
    {
        return {false, minCnt};
    }
    
    //무조건 짐
    return {true, maxCnt};
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    auto [win, cnt] = moveA(board, aloc, bloc);
    
    return cnt;
}