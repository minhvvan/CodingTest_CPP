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

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> Roads(N, vector<int>(N, 0));
    vector<int> Cities(M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Roads[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> Cities[i];
    }

    for (int i = 0; i < N; i++)
    {
        Roads[i][i] = 1;
    }

    //플루이드
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Roads[i][j] = Roads[i][j] | (Roads[i][k] & Roads[k][j]);
            }
        }
    }

    int currentCity = Cities[0]-1;
    for (int i = 1; i < M; i++)
    {
        if (Roads[currentCity][Cities[i] - 1])
        {
            currentCity = Cities[i] - 1;
            continue;
        }

        cout << "NO";
        return 0;
    }

    cout << "YES";

	return 0;
}