#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

int main() 
{
    INPUT_OPTIMIZE;

    while (cin >> N) 
    {
        int ans = 1;
        int k = 1;

        while (1) 
        {
            if (ans % N == 0) 
            {
                break;
            }
            else 
            {
                k++;
                ans = ans * 10 + 1;
                ans %= N;
            }
        }

        cout << k << "\n";
    }
   
    return 0;
} 