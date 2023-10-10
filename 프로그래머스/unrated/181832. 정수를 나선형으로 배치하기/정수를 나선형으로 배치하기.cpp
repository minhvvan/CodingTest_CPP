#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    vector<int> dy = {0, 1, 0, -1};    
    vector<int> dx = {1, 0, -1, 0};    
    int dir = 1;
    int limit = n-1;
    int num = n;
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        answer[0][i] = i+1;
    }
    
    int y = 0;
    int x = n-1;
    
    for(int t = 0; t < 2*n-2; t++)
    {
        for(int i = 0; i < limit; i++)
        {
            answer[y][x] = num++;
            
            y += dy[dir];
            x += dx[dir];
        }
        
        //change dir
        dir = (dir+1) % 4;
        cnt++;
        
        if(cnt == 2)
        {
            cnt = 0;
            limit--;
        }
    }
    
    answer[y][x] = num;
    
    return answer;
}