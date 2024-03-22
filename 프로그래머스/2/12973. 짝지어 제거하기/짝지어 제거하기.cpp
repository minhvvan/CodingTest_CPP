#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    if(s.size() % 2 == 1) return 0;

    vector<int> unremovedIdx;
    
    unremovedIdx.push_back(0);
    char prev = s[0];
    
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == prev)
        {
            unremovedIdx.pop_back();
            if(!unremovedIdx.empty()) prev = s[unremovedIdx.back()];
            else prev = ' ';
        }
        else
        {
            prev = s[i];
            unremovedIdx.push_back(i);
        }
    }
    
    return unremovedIdx.size() == 0;
}