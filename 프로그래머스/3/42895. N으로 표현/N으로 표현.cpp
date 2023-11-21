#include <string>
#include <vector>

using namespace std;

int makeNum(int N, int cnt)
{
    int result = 0;
    
    for(int i = 0; i < cnt; i++)
    {
        result *= 10;
        result += N;
    }
    
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    
    if(N == number) return 1;
    
    vector<vector<int>> dp(9);
    dp[1].push_back(N);
    
    for(int i = 2; i <= 8; i++)
    {
        dp[i].push_back(makeNum(N, i));
        
        for(int j = 1; j < i; j++)
        {
            for(auto num1 : dp[j])
            {
                for(auto num2 : dp[i-j])
                {
                    dp[i].push_back(num1 + num2);
                    dp[i].push_back(num1 - num2);
                    dp[i].push_back(num1 * num2);
                    
                    if(num2 == 0) continue;
                    dp[i].push_back(num1 / num2);
                }
            }
        }
        
        for(auto result : dp[i])
        {
            if(result == number)
            {
                return i;
            }
        }
    }
    
    return -1;
}