#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    int maxLen = 0;
    
    for(auto info : musicinfos)
    {
        vector<string> infos;
        string token;
        istringstream iss(info);
    
        while(getline(iss, token, ','))
        {
            infos.push_back(token);
        }
        
        string start = infos[0];
        string end = infos[1];
        
        int diff = (end[0]-'0' - (start[0]-'0')) * 10 + (end[1]-'0' - (start[1]-'0'));
        diff *= 60;
        diff += (end[3]-'0' - (start[3]-'0')) * 10 + (end[4]-'0' - (start[4]-'0'));
        
        string melody("");
        int cursor = 0;
        for(int i = 0; i < diff; i++)
        {
            melody += infos[3][cursor];
            cursor++;
            
            if(infos[3][cursor] == '#')
            {
                melody += infos[3][cursor];
                cursor++;
            }
            
            cursor = cursor % infos[3].size();
        }
        
        int pos = melody.find(m);
        while(pos != string::npos)
        {
            if(melody[pos+m.size()] == '#')
            {
                pos = melody.find(m, pos+m.size());
                continue;
            }
            
            if(maxLen < melody.size())
            {
                maxLen = melody.size();
                answer = infos[2];
            }
            break;
        }
    }
    
    return answer;
}