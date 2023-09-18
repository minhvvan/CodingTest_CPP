#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> converted;

void Convert(int n, int k)
{
    if(n < k)
    {
        converted.push_back(n);
        return;
    }
    
    Convert(n/k, k);
    converted.push_back(n%k);
}

bool isPrime(long long n)
{
    if(n < 2) return false;
    
    for(long long i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) 
        {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    Convert(n, k);
    
    long long temp = 0;
    for(auto c : converted)
    {
        if(c == 0){
            if(isPrime(temp))
            {
                answer++;
            }
            temp = 0;
        }
        else
        {
            temp *= 10;
            temp += c;
        }
    }
    
    if(isPrime(temp))
    {
        answer++;
    }
    
    
    
    return answer;
}