#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;


int solution(int n) {
    int answer = 0;
    int div = 1'000'000'007;
    
    //0: l,r,u, 1: ⨅ 
    vector<vector<long long>> tile(n+1, vector<long long>(8, 0));
    
    //1줄은 001, 100, 111만 가능
    tile[1][1] = 1;
    tile[1][4] = 1;
    tile[1][7] = 1;
    
    // 000 001 010 011 100 101 110 111
    
    // 001
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(j == 0)
            {
                tile[i][j] += tile[i-1][1] % div;
                tile[i][j] += tile[i-1][4] % div;
            }
            
            if(j == 1 || j == 4)
            {
                tile[i][j] += tile[i-1][0] % div;
            }
            
            tile[i][j] += tile[i-1][7^j] % div;
        }
    }

    
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 0; j < 8; j++)
//         {
//             cout << tile[i][j] << " ";
//         }
        
//         cout << "\n";
//     }
    
    return tile[n][0] % div;
}