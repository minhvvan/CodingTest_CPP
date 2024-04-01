#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

void Check(string ban, vector<string>& user_id, unordered_set<string>& FilterIdx)
{
    for(int i = 0 ; i < user_id.size(); i++)
    {
        if(ban.size() != user_id[i].size()) continue;
        
        string user = user_id[i];
        bool bMatch = true;
        for(int j = 0; j < ban.size(); j++)
        {
            if(ban[j] == '*') continue;
            if(ban[j] != user[j]) 
            {
                bMatch = false;
                break;
            }
        }
        
        if(bMatch)
        {
            FilterIdx.insert(user_id[i]);
        }
    }
}


int MakeComb(vector<unordered_set<string>>& FilterIdx, int depth, unordered_set<string>& comb, vector<unordered_set<string>>& results)
{
    if(depth == FilterIdx.size())
    {
        for(auto result : results)
        {
            bool bMatch = true;
            
            for(auto name : comb)
            {
                if(result.count(name) == 0)
                {
                    bMatch = false;
                    break;
                }
            }
            
            if(bMatch) return 0;
        }
        
        results.push_back(comb);
        return 1;
    }
    
    int result = 0;
    for(auto idx : FilterIdx[depth])
    {
        if(comb.count(idx) != 0) continue;
        
        comb.insert(idx);
        result += MakeComb(FilterIdx, depth+1, comb, results);

        comb.erase(idx);
    }
    
    return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<unordered_set<string>> FilterIdx(banned_id.size());
    
    for(int i = 0 ; i < banned_id.size(); i++)
    {
        Check(banned_id[i], user_id, FilterIdx[i]);
    }
    
    unordered_set<string> comb;
    vector<unordered_set<string>> results;
    
    answer = MakeComb(FilterIdx, 0, comb, results);
    
    return answer;
}