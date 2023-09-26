#include <string>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& tile, vector<int>& temp)
{
    if(temp.size() == 3)
    {
        
        return;
    }
    
    for(int i = 0; i < 2; i++)
    {
        temp.push_back(i);
        fill(tile, temp);
        
        temp.pop_back();
    }
}

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