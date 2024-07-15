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
const int DIV = 1'000'000'000;
const int MAX = 101;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> dp(N+1, vector<int>(10, 0));

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        
        for (int j = 1; j <= 8; j++)
        {
            dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
        }

        dp[i][9] = dp[i - 1][8];
    }

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + dp[N][i]) % DIV;
    }

    cout << result << "\n";

    return 0;
}