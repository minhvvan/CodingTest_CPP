#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

void Div(int n, map<int, int>& Prime)
{
    if(n == 1) return;
    
    vector<int> temp;
    while(n > 1)
    {
        bool canDiv = false;
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                temp.push_back(i);
                n /= i;
                
                canDiv = true;
                break;
            }
        }

        if(!canDiv)
        {
            temp.push_back(n);
            break;
        }
    }
    
    map<int,int> Current;
    for(auto num : temp)
    {
        Current[num]++;
    }
    
    for(auto [num, cnt] : Current)
    {
        if(Prime[num] < cnt)
        {
            Prime[num] += (cnt - Prime[num]);
        }
    }
}

int solution(vector<int> arr) {
    int answer = 1;
    
    map<int, int> Prime;
    
    for(int num : arr)
    {
        Div(num, Prime);
    }
    
    for(auto [num, cnt] : Prime)
    {
        // cout << num << ": " << cnt << ", ";
        answer *= pow(num,cnt);
        
    }
    
    return answer;
}