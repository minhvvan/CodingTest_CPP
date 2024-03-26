#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    
    bool bMinus = false;
    string temp;
    for(char c : s)
    {
        if(c == ' ')
        {
            //make num
            int current = stoi(temp);
            if(bMinus) current *= -1;
            
            minNum = min(minNum, current);
            maxNum = max(maxNum, current);
            
            temp = "";
            bMinus = false;
        }
        else if(c == '-') bMinus = true;
        else temp += c;
    }
    
    int current = stoi(temp);
    if(bMinus) current *= -1;

    minNum = min(minNum, current);
    maxNum = max(maxNum, current);

    temp = "";
    bMinus = false;
    
    answer += to_string(minNum);
    answer += " ";
    answer += to_string(maxNum);
    
    return answer;
}