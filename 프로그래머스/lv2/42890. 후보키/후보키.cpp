#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int cnt = 0;
vector<vector<int>> comb;

bool cmp(vector<int>& a, vector<int> b)
{
    return a.size() < b.size();
}

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

void makeComb(vector<vector<string>>& relation, int depth, vector<int>& temp)
{       
    if(depth == relation[0].size())
    {
        comb.push_back(temp);
        return;
    }
    
    temp.push_back(depth);
    makeComb(relation, depth+1, temp);
    
    temp.pop_back();
    makeComb(relation, depth+1, temp);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    vector<int> temp;
    makeComb(relation, 0, temp);
    
    set<vector<int>> keys;
    
    sort(comb.begin(), comb.end(), cmp);
    for(auto c: comb)
    {
        if(checkKey(relation, c))
        {
            if(keys.size() == 0) 
            {
                keys.insert(c);
                answer++;
                continue;
            }
            
            bool flag = true;
            for(auto key : keys)
            {
                vector<int> diff;
                set_difference(key.begin(),key.end(),c.begin(),c.end(), std::back_inserter(diff));
                
                if(diff.size() == 0) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                keys.insert(c);
                answer++;
            }
        }
    }
    
    
    
    return answer;
}