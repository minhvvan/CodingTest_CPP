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
int ans = INT_MAX;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T-- > 0)
    {
        int N;
        cin >> N;

        vector<int> Files(N+1);
        vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
        vector<int> sum(N+1, 0);
        for (int i = 1; i <= N; i++)
        {
            cin >> Files[i];
            sum[i] = sum[i - 1] + Files[i];
        }

        for (int k = 1; k < N; k++)
        {
            for (int start = 1; start + k <= N; start++)
            {
                int end = start + k;
                DP[start][end] = INT_MAX;

                for (int mid = start; mid < end; mid++)
                {
                    DP[start][end] = min(DP[start][end], DP[start][mid] + DP[mid + 1][end] + sum[end] - sum[start - 1]);
                }
            }
        }

        cout << DP[1][N] << "\n";
    }


    return 0;
}