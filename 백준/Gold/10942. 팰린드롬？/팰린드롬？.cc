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

long long N, M;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> Nums(N+1);
    vector<vector<bool>> DP(N+1, vector<bool>(N+1, false));

    for (int i = 1; i <= N; i++)
    {
        DP[i][i] = true;
        cin >> Nums[i];

        if (i > 1)
        {
            if (Nums[i] == Nums[i - 1])
            {
                DP[i - 1][i] = true;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        int Start = 1;
        int End = Start + i;

        while (End <= N)
        {
            if (DP[Start + 1][End - 1])
            {
                if (Nums[Start] == Nums[End])
                {
                    DP[Start][End] = true;
                }
            }

            Start++;
            End++;
        }
    }


    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;

        if (DP[S][E]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}