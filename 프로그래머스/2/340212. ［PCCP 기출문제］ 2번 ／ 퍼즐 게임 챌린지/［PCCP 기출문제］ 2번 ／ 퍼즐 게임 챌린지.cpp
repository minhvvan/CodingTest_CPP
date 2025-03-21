#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> Diffs;
vector<int> Times;
long long Limit;

bool Check(int level)
{
    long long total = 0;
    for(int i = 0 ; i < Diffs.size(); i++)
    {
        if(Diffs[i] <= level) total += Times[i];
        else
        {
            total += (Diffs[i]-level) * (Times[i] + Times[i-1]) + Times[i];
        }
    }
    
    return total <= Limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = INT_MAX;
    
    Diffs = move(diffs);
    Times = move(times);
    Limit = limit;
    
    int left = 1;
    int right = 100'000;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(Check(mid))
        {
            right = mid - 1;
            answer = min(answer, mid);
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}