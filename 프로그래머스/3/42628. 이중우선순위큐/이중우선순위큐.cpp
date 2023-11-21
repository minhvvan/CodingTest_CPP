#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(auto oper : operations)
    {
        int num = 0;
        
        if(oper[0] == 'I')
        {
            for(int i = 2; i < oper.size(); i++)
            {
                if(oper[i] == '-') continue;
                num *= 10;
                num += oper[i] - '0';
            }
            
            if(oper[2] == '-') num *= -1;
            
            dq.push_back(num);
        }
        if(oper[0] == 'D')
        {
            if(dq.empty()) continue;
            
            if(oper[2] == '-')
            {
                //최솟값
                dq.pop_front();
            }
            else
            {
                //최댓값
                dq.pop_back();
            }
        }
        sort(dq.begin(), dq.end(), [](int a, int b) { return a < b; });
    }
    
    if(dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}