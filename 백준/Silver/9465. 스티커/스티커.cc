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

int DP(vector<vector<int>>& Stickers, int N)
{
    vector<vector<int>> result(2, vector<int>(N, 0));
    result[0][0] = Stickers[0][0];
    result[1][0] = Stickers[1][0];

    for (int j = 1; j < N; j++)
    {
        result[0][j] = max(result[0][j - 1], result[1][j - 1] + Stickers[0][j]);
        result[1][j] = max(result[1][j - 1], result[0][j - 1] + Stickers[1][j]);
    }
    
    return max(result[0][N-1], result[1][N - 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int N;
        cin >> N;

        vector<vector<int>> Stickers(2, vector<int>(N));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Stickers[i][j];
            }
        }

        cout << DP(Stickers, N) << "\n";
    }

    return 0;
}