#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int M, N;

void Print(vector<vector<int>>& larvas)
{
    for (auto row : larvas)
    {
        for (auto larva : row)
        {
            cout << larva << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    const int GROWSIZE = M * 2 - 1;

    vector<int> growth(GROWSIZE,0);
    vector<vector<int>> larvas(M, vector<int>(M, 1));

    for (int i = 0; i < N; i++)
    {
        int idx = 0;
        for (int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;

            for (int k = 0; k < num; k++) growth[idx++] += j;
        }
    }

    int idx = 0;

    for (int j = M - 1; j >= 0; j--) larvas[j][0] += growth[idx++];
    for (int x = 1; x < M; x++)
    {
        for (int y = 0; y < M; y++)
        {
            larvas[y][x] += growth[idx];
        }
        idx++;
    }

    Print(larvas);

	return 0;
}