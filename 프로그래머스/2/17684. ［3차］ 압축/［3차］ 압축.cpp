#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Check(string& msg, vector<string>& Dictionary)
{
    for(int i = 1; i < Dictionary.size(); i++)
    {
        if(Dictionary[i] == msg) 
        {
            return i;
        }
    }
    
    return 0;
}

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> Dictionary;
    
    Dictionary.push_back("");
    
    for(char i = 'A'; i <= 'Z'; i++)
    {
        string temp;
        temp += i;
        Dictionary.push_back(temp);
    }
    
    for(int i = 0; i < msg.size(); i++)
    {
        string temp;
        temp += msg[i];
        
        int offset = 1;
        int idx = 0;
        
        while(true)
        {
            int newIdx = Check(temp, Dictionary);
            if(newIdx == 0)
            {
                i--;
                answer.push_back(idx);
                Dictionary.push_back(temp);
                break;
            }
            else
            {
                idx = newIdx;
                temp += msg[++i];
            }
        }
    }
    
    return answer;
}