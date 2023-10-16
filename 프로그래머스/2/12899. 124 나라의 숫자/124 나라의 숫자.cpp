#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void convert(vector<int>& numbers, int n)
{
    if(n < 3)
    {
        numbers.push_back(n);
        return;
    }
    
    convert(numbers, n/3 - 1);
    numbers.push_back(n%3);
}


string solution(int n) {
    string answer = "";
    
    vector<int> converted;
    
    convert(converted, n-1);
    
    for(auto c : converted)
    {
        int temp = pow(2,c);
        answer += temp+'0';
    }
    
    return answer;
}