#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int videoLen;
int cursor;
int vStart;
int vEnd;

int Convert(string time)
{
    int result = time[0] - '0';
    
    for(int i = 1 ; i < time.length(); i++)
    {
        if(i == 2) continue;
        result *= 10;
        result += time[i] - '0';
    }
    
    return result;
}

void Next()
{
    cursor += 10;
    int rest = cursor % 100;
    if(rest >= 60)
    {
        cursor /= 100;
        cursor++;
        cursor *= 100;
        rest-=60;
        cursor += rest;
    }

    if(cursor >= videoLen) cursor = videoLen;
    if(vStart <= cursor && cursor <= vEnd) cursor = vEnd;
}

void Prev()
{
    int rest = cursor % 100;
    if(rest < 10)
    {
        cursor /= 100;
        cursor--;
        if(cursor < 0) cursor = 0;
        else
        {
            cursor *= 100;
            cursor += (rest + 60);
        }
    }
    
    cursor -= 10;

    if(cursor < 0) cursor = 0;
    if(vStart <= cursor && cursor <= vEnd) cursor = vEnd;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    videoLen = Convert(video_len);
    cursor = Convert(pos);
    vStart = Convert(op_start);
    vEnd = Convert(op_end);
    
    if(vStart <= cursor && cursor <= vEnd) cursor = vEnd;
    
    for(int i = 0 ; i < commands.size(); i++)
    {
        if(commands[i] == "next")
        {
            Next();
        }
        else
        {
            Prev();
        }
    }
    
    
    answer += to_string(cursor/100);
    if(cursor/100 < 10) answer = "0" + answer;
    answer += ":";
    if(cursor%100 < 10) answer += "0" + to_string(cursor%100);
    else answer += to_string(cursor%100);
    
    return answer;
}