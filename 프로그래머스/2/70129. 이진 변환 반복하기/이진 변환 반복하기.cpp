#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Convert(int n, vector<int>& nums)
{
    if(n < 2)
    {
        nums.push_back(n);
        return;
    }
    
    Convert(n/2, nums);
    nums.push_back(n%2);
}

void Calc(vector<int>& nums, int& zeroCnt)
{
    vector<int> temp;
    int oneCnt = 0;
    
    for(auto num : nums)
    {
        if(num == 0) zeroCnt++;
        else oneCnt++;
    }
    
    Convert(oneCnt, temp);
    nums = temp;
}


vector<int> solution(string s) {
    vector<int> answer;
    vector<int> currentNum;
    
    int zeroCnt = 0;
    int tryCnt = 0;
    
    for(auto c : s)
    {
        if(c == '0') currentNum.push_back(0);
        else currentNum.push_back(1);
    }
    
    while(currentNum.size() != 1)
    {
        tryCnt++;
        Calc(currentNum, zeroCnt);
    }
    
    answer.push_back(tryCnt);
    answer.push_back(zeroCnt);
    
    return answer;
}