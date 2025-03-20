#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    n--;
    num--;
        
    int row = num / w;
    int col = num % w;
    int dir = row % 2 == 0 ? 1 : -1;
    
    if(dir == -1)
    {
        col = w - col - 1;
    }
    
    int lastRow = n / w;
    int lastCol = n % w;
    int lastDir = lastRow % 2 == 0 ? 1 : -1;
    
    if(lastDir == -1)
    {
        lastCol = w - lastCol - 1;
    }
    
    
    answer += (lastRow - row);
    
    if(lastDir == 1)
    {
        if(col <= lastCol) answer++;
    }
    else
    {
        if(col >= lastCol) answer++;
    }
    
    return answer;
}