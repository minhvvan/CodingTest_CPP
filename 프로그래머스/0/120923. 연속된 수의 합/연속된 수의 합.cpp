#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int n = (total*2/num-num+1) / 2;
    
    for(int i = n; i < n+num; i++)
    {
        answer.push_back(i);
    }
    
    return answer;
}