#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> jump(n+1, 0);
    
    jump[0] = 1;
    jump[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        jump[i] = (jump[i-2] + jump[i-1]) % 1234567;
    }
    
    answer = jump[n];
    return answer;
}