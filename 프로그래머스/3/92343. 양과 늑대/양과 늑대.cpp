#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

enum
{
    SHEEP,
    WOLF
};

int answerTemp = 0;

void DFS(vector<vector<int>>& land, vector<int>& info, unordered_set<int>& Connected, int diff, int sheep)
{
    if(diff <= 0)
    {
        answerTemp = max(answerTemp, sheep);
        return;
    }
        
    for(auto next : Connected)
    {
        unordered_set<int> tempSet = Connected;
        tempSet.erase(next);
        for(int temp : land[next]) tempSet.insert(temp);
        
        if(info[next] == SHEEP) DFS(land, info, tempSet, diff+1, sheep+1);
        else DFS(land, info, tempSet, diff-1, sheep);
    }
    
    answerTemp = max(answerTemp, sheep);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    int n = info.size();
    
    vector<vector<int>> land(n+1);
    for(auto& edge : edges) land[edge[0]].push_back(edge[1]);
   
    unordered_set<int> Connected;
    for(int next : land[0]) Connected.insert(next);
    
    DFS(land, info, Connected, 1, 1);
    
    answer = answerTemp;
    return answer;
}