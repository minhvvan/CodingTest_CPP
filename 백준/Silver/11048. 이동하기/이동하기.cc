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
int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> Candy(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Candy[i][j];
        }
    }

    dp[1][1] = Candy[1][1];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int result = max(dp[i - 1][j], dp[i][j - 1]);
            result = max(result, dp[i - 1][j - 1]);

            dp[i][j] = result + Candy[i][j];
        }
    }

    cout << dp[N][M];

    return 0;
}