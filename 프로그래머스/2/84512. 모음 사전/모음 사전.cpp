#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void MakePer(vector<string>& per, string temp, int depth, string Alpha)
{
    if(depth == 5)
    {
        return;
    }
    
    for(int i = 0; i < 5; i++)
    {
        temp += Alpha[i];
        per.push_back(temp);
        MakePer(per, temp, depth+1, Alpha);
        
        temp.pop_back();
    }
}


int solution(string word) {
    int answer = 0;
    
    vector<string> per;
    string Alpha = "AEIOU";
    string temp;
    
    MakePer(per, temp, 0, Alpha);
    
    for(int i = 0 ; i < per.size(); i++)
    {
        if(per[i] == word)
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}