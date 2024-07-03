#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int N;

bool GetPossible(string a, string b, string c)
{
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

    dp[0][0] = 1;

    int alen = a.size();
    int blen = b.size();

    for (int i = 1; i <= alen; i++) 
    { 
        if (a[i - 1] == c[i - 1] && dp[i - 1][0]) dp[i][0] = 1;
    }

    for (int i = 1; i <= blen; i++) 
    {
        if (b[i - 1] == c[i - 1] && dp[0][i - 1]) dp[0][i] = 1;
    }

    for (int i = 1; i <= alen; i++) 
    { 
        for (int j = 1; j <= blen; j++)
        {
            if ((dp[i - 1][j] && a[i - 1] == c[i + j - 1]) || (dp[i][j - 1] && b[j - 1] == c[i + j - 1]))
            {
                dp[i][j] = 1;
            }
        }
    }

    return dp[alen][blen];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int t = 1; t <= N; t++)
    {
        string a, b, c;
        cin >> a >> b >> c;

        if (GetPossible(a, b, c)) cout << "Data set " << t << ": yes\n";
        else cout << "Data set " << t << ": no\n";
    }


    return 0;
}