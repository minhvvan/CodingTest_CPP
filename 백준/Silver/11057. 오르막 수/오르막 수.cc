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
const int DIV = 10'007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    //i자리
    for (int i = 2; i <= N; i++)
    {
        //j로 끝나는
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % DIV;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans = (ans + dp[N][i]) % DIV;
    }

    cout << ans;

    return 0;
}