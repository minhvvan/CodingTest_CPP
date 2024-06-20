#include <stdio.h>
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
const int MAX = 1000 * 1000 + 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<vector<int>> RGBs(N, vector<int>(3));
    vector<vector<int>> DP(N, vector<int>(3, MAX));
    int ans = MAX;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> RGBs[i][j];
        }
    }

    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == k) DP[0][i] = RGBs[0][i];
            else DP[0][i] = MAX;
        }

        for (int i = 1; i < N; i++)
        {
            DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + RGBs[i][0];
            DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + RGBs[i][1];
            DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + RGBs[i][2];
        }

        int temp = min(DP[N - 1][(k + 1) % 3], DP[N - 1][(k + 2) % 3]);
        ans = min(ans, temp);
    }

    cout << ans;

    return 0;
}