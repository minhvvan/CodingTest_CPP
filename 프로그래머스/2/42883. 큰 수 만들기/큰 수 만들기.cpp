#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int temp = number.size() - k;
    
    queue<int> num;
    vector<int> result;
    for(auto c : number)
    {
        num.push(c-'0');
    }
    
    while(!num.empty() && k > 0)
    {
        result.push_back(num.front());
        num.pop();
        
        while(!result.empty() && result.back() < num.front() && k>0) {
            result.pop_back();
            k--;
        }
    }
    
    while(!num.empty())
    {
        result.push_back(num.front());
        num.pop();
    }

    
    for(int i = 0; i < temp; i++)
    {
        int n = result[i];
        answer += n+'0';
    }
    

    
    return answer;
}