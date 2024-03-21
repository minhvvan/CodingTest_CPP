#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Roll(int currentSum, vector<int>& rollSum, int depth, vector<int>& picks, vector<vector<int>>& dice)
{
    if(depth == picks.size())
    {
        rollSum.push_back(currentSum);
        return;
    }
    
    for(int i = 0; i < 6; i++)
    {
        currentSum += dice[picks[depth]][i];
        Roll(currentSum, rollSum, depth+1, picks, dice);

        currentSum -= dice[picks[depth]][i];
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    //완탐
    //n개중 n/2개 고르기
    vector<vector<int>> APicks;
    vector<vector<int>> BPicks;
    
    vector<int> temp;
    vector<vector<int>> roll;
    
    for(int i = 0; i < (1 << dice.size()); i++)
    {
        vector<int> AtempPick;
        vector<int> BtempPick;
        
        for(int j = 0; j < dice.size(); j++)
        {
            if(i & (1 << j)) AtempPick.push_back(j);
            else BtempPick.push_back(j);
        }
        
        if(AtempPick.size() == BtempPick.size())
        {
            APicks.push_back(AtempPick);
            BPicks.push_back(BtempPick);
        }
    }
    
    
    int maxWin = 0;
    vector<int> candidate;
    
    for(int i = 0; i < APicks.size(); i++)
    {
        vector<int> ASums;
        Roll(0, ASums, 0, APicks[i], dice);
        
        vector<int> BSums;
        Roll(0, BSums, 0, BPicks[i], dice);
        
        sort(ASums.begin(),ASums.end());
        sort(BSums.begin(),BSums.end()); 
        
        int winRate = 0;
        for(int n : ASums){
            int win = lower_bound(BSums.begin(), BSums.end(), n) - BSums.begin(); 
            if(win - 1 > 0) winRate += win; 
        }
        
        if(winRate > maxWin)
        {
            maxWin = winRate;
            candidate = APicks[i];
        }
    }
    
    
    
    for(int i = 0; i < candidate.size(); i++)
    {
        answer.push_back(candidate[i]+1);
    }
    
    return answer;
}