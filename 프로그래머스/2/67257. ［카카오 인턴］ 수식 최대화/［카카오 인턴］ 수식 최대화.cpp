#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

tuple<vector<long long>, vector<string>> split(string expr)
{
    vector<long long> num;
    vector<string> oper;
    
    long long temp = 0;
    for(auto c : expr)
    {
        if(c == '-' || c == '*' || c == '+')
        {
            num.push_back(temp);
            string op;
            op += c;
            oper.push_back(op);
            temp = 0;
            
            continue;
        }
        
        temp *= 10;
        temp += c - '0';
    }
    
    num.push_back(temp);
    
    return {num, oper};
}

long long operation(long long a, long long b, string op)
{
    if(op == "+")
    {
        return a + b;
    }
    else if(op == "-")
    {
        return a - b;
    }
    else
    {
        return a * b;
    }
}


void makeComb(vector<int>& comb, vector<bool>& checked, vector<long long> num, vector<string> oper, long long& answer)
{
    if(comb.size() == 3)
    {
        //계산
        for(int i = 0; i < 3; i++)
        {
            string op;
            if(comb[i] == 0) op = "+";
            if(comb[i] == 1) op = "-";
            if(comb[i] == 2) op = "*";
            
            int cnt = 0;
            
            for(int j = 0; j < oper.size(); j++)
            {
                if(oper[j] == op)
                {
                    auto result = operation(num[j-cnt], num[j-cnt+1], oper[j]);
                
                    num.erase(num.begin() + (j-cnt+1));
                    num.erase(num.begin() + j-cnt);
                    num.insert(num.begin() + j-cnt, result);
                    
                    cnt++;
                }
            }
            oper.erase(std::remove(oper.begin(), oper.end(), op), oper.end());
        }
        
        answer = max(answer, abs(num[0]));
    }
    
    for(int i = 0; i < 3; i++)
    {
        if(checked[i]) continue;
        
        checked[i] = true;
        comb.push_back(i);
        
        makeComb(comb, checked, num, oper, answer);
        comb.pop_back();
        checked[i] = false;
    }
}



long long solution(string expression) {
    long long answer = 0;
    
    auto [num, oper] = split(expression);
    
    vector<int> comb;
    vector<bool> checked(3, false);
    
    makeComb(comb, checked, num, oper, answer);
    
    return answer;
}