#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    vector<int> aNum;
    vector<int> bNum;
    
    int originA = a;
    int originB = b;
    while(a >= 10)
    {
        aNum.push_back(a%10);
        a /= 10;
    }
    aNum.push_back(a);
    
    while(b >= 10)
    {
        bNum.push_back(b%10);
        b /= 10;
    }
    bNum.push_back(b);
    
    reverse(aNum.begin(), aNum.end());
    reverse(bNum.begin(), bNum.end());

    int tempA = originA;
    for(int i = 0; i < bNum.size(); i++)
    {
        tempA *= 10;
        tempA += bNum[i];
    }
    
    int tempB = originB;
    for(int i = 0; i < aNum.size(); i++)
    {
        tempB *= 10;
        tempB += aNum[i];
    }

    return tempA > tempB ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(auto num : numbers)
    {
        answer += to_string(num);
    }
    
    bool flag = true;
    for(auto a : answer)
    {
        if(a-'0' != 0)
        {
            flag = false;
            break;
        }
    }
    
    if(flag) answer = "0";
    
    return answer;
}