#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    const int MAX = 10'000'000;
    
    for(int i = begin; i <= end; i++)
    {
        if(i == 1) 
        {
            answer.push_back(0);
            continue;
        }
        
        bool flag = true;
        int temp = 1;
        for(int j = 2; j <= sqrt(i); j++)
        {
            // j는 나누는 수
            if(i%j == 0)
            {
                if(i/j <= MAX)
                {
                    answer.push_back(i/j);
                    flag = false;
                    break;
                }
                
                temp = max(temp, j);
            }
        }
        
        if(flag)
        {
            answer.push_back(temp);
        }

    }
    
    
    return answer;
}