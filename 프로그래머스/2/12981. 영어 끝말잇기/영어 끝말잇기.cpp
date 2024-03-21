#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> told;
    
    int round = 0;
    int who = 0;
    
    told.insert(words[0]);
    for(int i = 1; i < words.size(); i++)
    {
        if(told.count(words[i]) == 0) told.insert(words[i]);
        else
        {
            who = (i % n) + 1;
            round = (i / n) + 1;
            break;
        }
        
        if(words[i-1][words[i-1].size()-1] != words[i][0])
        {
            who = (i % n) + 1;
            round = (i / n) + 1;
            break;
        }
    }
    
    answer.push_back(who);
    answer.push_back(round);
    return answer;
}