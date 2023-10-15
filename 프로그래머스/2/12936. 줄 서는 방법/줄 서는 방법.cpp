#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findK(int k, int n, vector<bool>& checked)
{
    for(int i = 1; i <= n; i++)
    {
        if(checked[i]) continue;
        
        k--;
        if(k==0)
        {
            checked[i] = true;
            return i;
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<bool> checked(n+1, false);
    vector<long long> fact;

    fact.push_back(0);
    fact.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        fact.push_back(fact[i-1] * i);
    }
    
    for(int i = n-1; i > 0; i--)
    {
        int temp = (k / fact[i]) + 1;
        
        if((k % fact[i]) == 0)
        {
            temp--;
            k = fact[i];
        }
        else
        {
            k %= fact[i];
        }
        
        answer.push_back(findK(temp, n, checked));
    }
    
    answer.push_back(findK(1, n, checked));
    
    return answer;
}