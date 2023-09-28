#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    const long long DIV = 1'000'000'007;
    
    vector<vector<long long>> tile(n+1, vector<long long>(2,0));
    
    tile[1][0] = 1;
    tile[1][1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        tile[i][0] += (tile[i-1][0] + tile[i-1][1]) % DIV;
        tile[i][1] += tile[i-1][0] % DIV;
    }
    
    answer = tile[n][0];
    
    return answer;
}