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

string str1, str2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int N = str1.size();
    int M = str2.size();
    cout << dp[N][M] << "\n";

    vector<char> lcs;
    while (dp[N][M] != 0)
    {
        if (dp[N][M] == dp[N - 1][M])
        {
            N--;
            continue;
        }
        if (dp[N][M] == dp[N][M - 1])
        {
            M--;
            continue;
        }

        lcs.push_back(str1[N-1]);
        N--;
        M--;
    }

    for (int i = lcs.size() - 1; i >= 0; i--)
    {
        cout << lcs[i];
    }

    return 0;
}