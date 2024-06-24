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

int N, K;
const int DIV = 1'000'000'003;
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

    for (int i = 0; i < N; ++i) 
    {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
        {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % DIV;
        }
    }

    cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % DIV << '\n';

    return 0;
}