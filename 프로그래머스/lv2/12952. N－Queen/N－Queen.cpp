#include <string>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void search(int n, int y, vector<int>& col, vector<int>& diag1, vector<int>& diag2)
{
    if(y == n)
    {
        cnt++;
        return;
    }
    
    for(int x = 0; x < n; x++)
    {
        if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        
        // cout<< "y: " << y << "\n";
        // cout<< "x: " << x << "\n";
        // cout<< "x+y: " << x+y << "\n";
        // cout<< "x-y+n-1: " << x-y+n-1 << "\n";
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        
//         cout << "size: " << diag2.size() << "\n";
//         cout<< "\n";
        
        search(n, y+1, col, diag1, diag2);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int solution(int n) {
    int answer = 0;
    
    vector<int> col(n, 0);
    vector<int> diag1(2*n, 0);
    vector<int> diag2(2*n, 0);
    
    search(n, 0, col, diag1, diag2);
    
    
    return cnt;
}