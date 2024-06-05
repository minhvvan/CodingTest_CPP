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

    vector<vector<int>> adj(N + 1);
    vector<vector<bool>> Upper(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> Lower(N + 1, vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++)
    {
        Upper[i][i] = true;
        Lower[i][i] = true;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        Upper[a][b] = true;
        Lower[b][a] = true;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                Upper[i][j] = Upper[i][k] && Upper[k][j] ? 1 : Upper[i][j];
                Lower[i][j] = Lower[i][k] && Lower[k][j] ? 1 : Lower[i][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;

        for (int j = 1; j <= N; j++)
        {
            if (Upper[i][j] == false && Lower[i][j] == false) cnt++;
        }

        cout << cnt << "\n";
    }

	return 0;
}