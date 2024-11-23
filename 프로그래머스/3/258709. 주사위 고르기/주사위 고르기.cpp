#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> dices;

void makeComb(vector<vector<int>>& comb, vector<int> temp, int depth)
{
    if(temp.size() == n/2)
    {
        comb.push_back(temp);
        return;
    }
    
    for(int i = depth; i < n; i++)
    {
        temp.push_back(i);
        makeComb(comb, temp, i+1);
        
        temp.pop_back();
    }
}

int convert(vector<int>& comb)
{
    int result = 0;
    
    for(int i = 0;i < comb.size(); i++)
    {
        result += (1 << comb[i]);
    }
    
    return result;
}

//comb안에 모든 주사위의 점수 조합을 만들어야 함
void makeScore(int result, int depth, vector<vector<int>>& scores, int combIdx, vector<int>& comb)
{
    if(depth == comb.size())
    {
        scores[combIdx].push_back(result);
        return;
    }
    
    for(int i = 0; i < 6; i++)
    {
        makeScore(result + dices[comb[depth]][i], depth + 1, scores, combIdx, comb);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    dices = dice;
    n = dice.size();
    
    //조합
    vector<vector<int>> comb;
    vector<int> temp;
    makeComb(comb, temp, 0);
    
    //각 조합에 대한 점수(모든 조합 = 10C5)
    vector<vector<int>> scores(40'000);
    for(int i = 0; i < comb.size(); i++)
    {
        int combIdx = convert(comb[i]);
        
        for(int j = 0; j < comb[i].size(); j++)
        {
            makeScore(0, 0, scores, combIdx, comb[i]);
            sort(scores[combIdx].begin(), scores[combIdx].end());
        }
    }
    
    const int maxIdx = (1 << n) - 1;
    int maxWin = 0;
    int winCombIdx = -1;
    for(int i = 0; i < comb.size(); i++)
    {
        int AIdx = convert(comb[i]);
        int BIdx = maxIdx - AIdx;
        
        int current = 0;
        for(int j = 0; j < scores[AIdx].size(); j++)
        {
            int win = lower_bound(scores[BIdx].begin(), scores[BIdx].end(), scores[AIdx][j]) - scores[BIdx].begin();
            current += win;
        }
        
        if(maxWin < current)
        {
            maxWin = current;
            winCombIdx = AIdx;
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(winCombIdx & (1 << i)) answer.push_back(i+1);
    }
    
    return answer;
}