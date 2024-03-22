#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    if(s.size() % 2 == 1) return 0;

    vector<char> unremoved;
    unremoved.push_back(s[0]);
    
    for(int i = 1; i < s.size(); i++)
    {
        if(unremoved.empty())
        {
            unremoved.push_back(s[i]);
            continue;
        }
        
        if(s[i] == unremoved.back()) unremoved.pop_back();
        else unremoved.push_back(s[i]);
    }
    
    return unremoved.size() == 0;
}