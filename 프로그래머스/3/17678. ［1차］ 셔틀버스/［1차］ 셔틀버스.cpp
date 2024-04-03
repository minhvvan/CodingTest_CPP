#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int Convert(string time)
{
    return ((time[0] - '0') * 10 + time[1] - '0') * 60 + (time[3] - '0') * 10 + (time[4] - '0');
}

string timeToString(int time)
{
    string result;
    
    int hour = time / 60;
    time -= hour * 60;
    
    if(hour / 10 < 1) result += "0";
    result += to_string(hour);
    result += ":";
    if(time / 10 < 1) result += "0";
    result += to_string(time);
    
    return result;
}

bool cmp(string& a, string& b)
{
    int timeA = Convert(a);
    int timeB = Convert(b);

    return timeA < timeB;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int currentTime = Convert("09:00");
    map<int, vector<int>> seat;
    
    sort(timetable.begin(), timetable.end(), cmp);
    
    for(int i = 0; i < n; i++)
    {
        seat[currentTime+(i*t)];
    }

    for(auto crew : timetable)
    {
        int time = Convert(crew);
        for(auto itr = seat.begin(); itr != seat.end(); itr++)
        {
            if(time <= itr->first && itr->second.size() < m)
            {
                itr->second.push_back(time);
                break;
            }
        }
    }
    
//     for(auto itr = seat.begin(); itr != seat.end(); itr++)
//     {
//         for(auto time : itr->second)
//         {
//             cout << timeToString(time) << " ";
//         }
//         cout << "\n";
//     }
    
    
    int tempAnswer = -1;
    for(auto itr = seat.rbegin(); itr != seat.rend(); itr++)
    {
        if(itr->second.size() < m)
        {
            tempAnswer = max(tempAnswer, itr->first);
        }
        else
        {
            tempAnswer = max(tempAnswer, itr->second[itr->second.size()-1]-1);
        }
    }
    
    answer = timeToString(tempAnswer);
    
    return answer;
}