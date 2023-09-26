#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //0: ⨅, 1: □
    vector<long long> tile(n+1, 0);
    vector<int> temp;
    
    tile[0] = 1;
    tile[2] = 3;

    for(int i = 4; i <= n; i++) {
        tile[i] += (tile[i - 2] * tile[2]) % 1'000'000'007;
        for(int j = 4; j <= i; j += 2) {
            tile[i] += (tile[i - j] * 2) % 1'000'000'007;
        }
    }
    
    answer = tile[n] % 1'000'000'007;

    return answer;
}