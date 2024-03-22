#include <iostream>
#include <vector>
using namespace std;


int solution(int n)
{
    if(n == 1 || n == 2) return 1;

    int ans = 0;

    while(n != 0)
    {
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n--;
            ans++;
        }
    }
    
    return ans;
}