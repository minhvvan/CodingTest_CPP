#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<bool> success;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int num = schedules.size();
    success.resize(num, true);
    
    for(auto& schedule : schedules)
    {
        int temp = schedule + 10;
        int rest = temp % 100;
        if(rest >= 60)
        {
            temp /= 100;
            temp++;
            temp *= 100;
            rest -= 60;
            temp += rest;
        }
        
        schedule = temp;
    }
    
    for(int i = 0; i < 7; i++)
    {
        int day = (startday + i) % 7;
        if(day == 6 || day == 0) continue;
        
        for(int j = 0; j < num; j++)
        {
            if(timelogs[j][i] > schedules[j])
            {
                success[j] = false;
            }
        }
    }
    
    for(auto s : success)
    {
        if(s) answer++;
    }
    
    return answer;
}