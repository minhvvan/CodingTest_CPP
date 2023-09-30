#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int cnt = 0;
set<vector<int>> candidate;

bool checkKey(vector<vector<string>>& relation, vector<int>& temp)
{
    int cntColumn = relation[0].size();
    int cntRow = relation.size();
    
    set<vector<string>> now;
    
    for(int i = 0; i < cntRow; i++)
    {
        vector<string> row;
        for(int j = 0; j < temp.size(); j++)
        {
            row.push_back(relation[i][temp[j]]);
        }
                                
        now.insert(row);
    }
    
    return (now.size() == cntRow);
}

void bfs(vector<vector<string>>& relation)
{
    int cntColumn = relation[0].size();
    queue<pair<int, vector<int>>> q;
    
    for(int i = 0; i < cntColumn; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        
        if(checkKey(relation, temp))
        {
            cnt++;
            candidate.insert(temp);
        }
        else
        {
            q.push({i, temp});
        }
    }
    
    while(!q.empty())
    {
        auto idx = q.front().first;
        auto temp = q.front().second;
        
        q.pop();
        
        for(int i = idx+1; i < cntColumn; i++)
        {
            temp.push_back(i);
            
            bool flag = true;
            for(auto key : candidate)
            {
                vector<int> diff;
                set_difference(key.begin(), key.end(), temp.begin(), temp.end(), std::back_inserter(diff));

                if(diff.size() == 0) 
                {
                    flag = false;
                    break;
                }
            }
                
            if(!flag)
            {
                temp.pop_back();
                continue;
            }
            
            
            if(checkKey(relation, temp))
            {
                cnt++;
                candidate.insert(temp);
            }
            else
            {
                q.push({i, temp});
            }
            
            temp.pop_back();
        }
    }
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    bfs(relation);
    // cout << cnt;
    
    
    return cnt;
}