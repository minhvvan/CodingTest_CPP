#include <string>
#include <vector>
#include <iostream>

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
    
    //2줄부터 가능한 수 세기
    for(int i = 2; i <= n; i++)
    {
    	//가능한 경우의 수 8개
        for(int j = 0; j < 8; j++)
        {
        	// 000 -> 100, 001을 윗 행으로 가질 수 있음
            if(j == 0)
            {
                tile[i][j] += tile[i-1][1] % div;
                tile[i][j] += tile[i-1][4] % div;
            }
            
            // 100, 001 -> 000을 윗 행으로 가질 수 있음
            if(j == 1 || j == 4)
            {
                tile[i][j] += tile[i-1][0] % div;
            }
            
            // 반전시킨 경우는 모든 조합에서 가능
            tile[i][j] += tile[i-1][7^j] % div;
        }
    }
    
    return tile[n][0] % div;
}