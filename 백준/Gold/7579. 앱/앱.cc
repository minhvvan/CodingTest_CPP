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

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<int> Apps(N+1);
    vector<int> costs(N+1);
    int Sum = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> Apps[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
        Sum += costs[i];
    }

    vector<vector<int>> DP(N+1, vector<int>(Sum+1, 0));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= Sum; j++)
        {
            if (j - costs[i] >= 0)
            {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - costs[i]] + Apps[i]);
            }

            DP[i][j] = max(DP[i][j], DP[i - 1][j]);
        }
    }

    for (int i = 0; i <= Sum; i++)
    {
        if (DP[N][i] >= M)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}