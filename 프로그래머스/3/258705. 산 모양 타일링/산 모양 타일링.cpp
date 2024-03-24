#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    int MOD = 10007;
    
    vector<int> dp1(tops.size(), 0);
    vector<int> dp2(tops.size(), 0);
    dp1[0] = 1;
    dp2[0] = 2 + tops[0];
    
    for(int i = 1; i < n; i++)
    {
        dp1[i] = (dp1[i - 1] + dp2[i - 1]) % MOD;
        dp2[i] = ((dp1[i - 1] * (1 + tops[i])) + (dp2[i - 1] * (2 + tops[i]))) % MOD;
    }
        
    return (dp1[n-1] + dp2[n-1]) % MOD;
}