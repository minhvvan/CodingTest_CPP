#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int IsPalindrome(const string& str, int start, int end)
{
    while(start >= 0 && end < str.size()) 
    {
        if (str[start] != str[end]) break;
        start--;
        end++;
    }
    
    return end - start - 1;
}

int solution(string s)
{
    const int N = s.length();
    
    int answer = 1;
    
    for(int i = 0 ; i < N; i++)
    {
        int temp = max(IsPalindrome(s, i, i), IsPalindrome(s, i, i+1));
        answer = max(answer, temp);
    }
    
    return answer;
}