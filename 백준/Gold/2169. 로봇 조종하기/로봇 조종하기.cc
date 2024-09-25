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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    vector<vector<int>> dpLeft(N + 1, vector<int>(M + 1, -100));
    vector<vector<int>> dpRight(N + 1, vector<int>(M + 1, -100));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> Mars(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Mars[i][j];
        }
    }

    //first row
    dpLeft[1][1] = Mars[1][1];
    dpRight[1][1] = Mars[1][1];
    for (int j = 2; j <= M; j++)
    {
        dpLeft[1][j] = dpLeft[1][j - 1] + Mars[1][j];
        dpRight[1][j] = dpRight[1][j - 1] + Mars[1][j];
    }

    for (int i = 2; i <= N; i++)
    {
        //Left
        dpLeft[i][1] = max(dpLeft[i - 1][1], dpRight[i - 1][1]) + Mars[i][1];
        for (int j = 2; j <= M; j++)
        {
            int temp = max(dpLeft[i - 1][j], dpLeft[i][j - 1]);
            temp = max(temp, dpRight[i - 1][j]) + Mars[i][j];
            dpLeft[i][j] = temp;
        }

        //Right
        dpRight[i][M] = max(dpRight[i - 1][M], dpLeft[i - 1][M]) + Mars[i][M];
        for (int j = M - 1; j > 0; j--)
        {
            int temp = max(dpRight[i][j + 1], dpRight[i - 1][j]);
            temp = max(temp, dpLeft[i - 1][j]) + Mars[i][j];
            dpRight[i][j] = temp;
        }
    }

    cout << dpLeft[N][M];

    return 0;
}