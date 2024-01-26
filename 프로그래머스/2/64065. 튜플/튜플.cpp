#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void Parse(vector<vector<int>>& nums, string s)
{
    vector<int> temp;
    bool bInsert = false;
    int num = 0;
    
    for(int i = 1; i < s.size()-1; i++)
    {
        char c = s[i];
        if(c == '{')
        {
            bInsert = true;
            continue;
        }
        
        if(c == '}')
        {
            bInsert = false;
            continue;
        }
        
        if(bInsert) 
        {
            if(c == ',')
            {
                temp.push_back(num);
                num = 0;
                continue;
            }
            else
            {
                num *= 10;
                num += c - '0';
            }
        }
        else
        {
            temp.push_back(num);
            nums.push_back(temp);
            temp.clear();
            num = 0;
        }
    }
    
    temp.push_back(num);
    nums.push_back(temp);
}

vector<int> solution(string s) {
    vector<int> answer;
    //{} 단위로 잘라서 vector에 넣음
    vector<vector<int>> tuples;
    set<int> checkInclude;
    
    
    Parse(tuples, s);
    
    //개수순서대로 정렬
    sort(tuples.begin(), tuples.end(), [](vector<int>& a, vector<int>& b){ return a.size() < b.size(); });
    for(auto tuple : tuples)
    {
        for(auto num : tuple)
        {
            // cout << num << " ";
            if(checkInclude.count(num) == 0)
            {
                checkInclude.insert(num);
                answer.push_back(num);
            }
        }
        // cout << "\n";
    }
    
    
    
    return answer;
}