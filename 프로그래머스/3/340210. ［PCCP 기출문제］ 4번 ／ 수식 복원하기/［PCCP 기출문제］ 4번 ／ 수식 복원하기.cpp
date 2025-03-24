#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int INVALID = 1234567;
vector<bool> possible(10, true);
vector<vector<int>> answerList;

int Plus(string a, string b, int d)
{
    int result = 0;
    int carry = 0;
    
    int aLen = a.length();
    int bLen = b.length();
    
    for(int i = 0; i < max(aLen, bLen); i++)
    {
        int aNum = 0;
        int bNum = 0;
        if(i < aLen) aNum = a[aLen - i - 1] - '0';
        if(i < bLen) bNum = b[bLen - i - 1] - '0';
        int sum = aNum + bNum + carry;
        carry = 0;
        
        int rest = sum % d;
        carry += sum / d;
        
        result += rest * pow(10, i);
    }
    
    if(carry != 0) result += carry * pow(10, max(aLen, bLen));
    
    return result;
}

int Minus(string a, string b, int d)
{
    int result = 0;
    int carry = 0;
    
    int aLen = a.length();
    int bLen = b.length();
    
    for(int i = 0; i < max(aLen, bLen); i++)
    {
        int aNum = 0;
        int bNum = 0;
        if(i < aLen) aNum = a[aLen - i - 1] - '0';
        if(i < bLen) bNum = b[bLen - i - 1] - '0';
        
        int sum = (aNum - carry) - bNum;
        carry = 0;
        
        if(sum < 0)
        {
            carry++;
            sum += d;
        }
        
        result += sum * pow(10, i);
    }
    
    return result;
}

struct Expr
{
    string num1, num2;
    bool bPlus;
    string result;
    int i;
    
    int Matching(int d)
    {
        int tempResult;
        if(bPlus) tempResult = Plus(num1, num2, d);
        else tempResult = Minus(num1, num2, d);
        
        if(result != "X")
        {
            if(tempResult == stoi(result)) return tempResult;
            return INVALID;
        }
        else
        {
            return tempResult;
        }
    }
    
    string Print()
    {
        string op = bPlus ? " + " : " - ";
        
        int r = INVALID;
        bool p = true;
        
        for(int j = 2; j < 10; j++)
        {
            if(!possible[j]) continue;
            
            if(r == INVALID)
            {
                r = answerList[i][j];
                continue;
            }
            
            if(r != answerList[i][j] && answerList[i][j] != INVALID)
            {
                p = false;
                break;
            }
        }
        
        if(!p) return num1 + op + num2 + " = ?";
        return num1 + op + num2 + " = " + to_string(r); 
    }
};

vector<Expr> exprs;

void CheckDigit(string num)
{
    for(auto c : num)
    {
        int digit = c - '0';
        while(digit > 1)
        {
            possible[digit--] = false;
        }
    }
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    answerList.resize(expressions.size(), vector<int>(10, INVALID));
    
    possible[0] = false;
    possible[1] = false;
    
    for(int i = 0 ; i < expressions.size(); i++)
    {
        auto& expression = expressions[i];
        istringstream iss(expression);
        string buffer;
        
        vector<string> splited;
        while(getline(iss, buffer, ' '))
        {
            splited.push_back(buffer);
        }
        
        exprs.push_back({splited[0], splited[2], splited[1] == "+", splited[4], i});
        
        CheckDigit(splited[0]);
        CheckDigit(splited[2]);
        
        if(splited[4] != "X")
        {
            CheckDigit(splited[4]);
        }
    }
    
    
    for(int i = 0; i < exprs.size(); i++)
    {
        for(int j = 2; j < 10; j++)
        {
            if(!possible[j]) continue;
            answerList[i][j] = exprs[i].Matching(j);
            
            if(exprs[i].result != "X" && answerList[i][j] != stoi(exprs[i].result))
            {
                possible[j] = false;
                continue;
            }
        }
    }
    
    for(auto& expr : exprs)
    {
        if(expr.result != "X") continue;
        answer.push_back(expr.Print());
    }
    
    return answer;
}