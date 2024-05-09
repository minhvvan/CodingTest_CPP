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

int ans = INT_MAX;
bool visited[10] = { false, };

void dfs(int start, int dist, int depth, vector<vector<int>>& Planets) 
{
    if (ans < dist) return;
    
    if (depth == Planets.size()) {
        ans = min(ans, dist);
        return;
    }

    for (int i = 0; i < Planets.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;

        dfs(i, dist + Planets[start][i], depth + 1, Planets);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<vector<int>> Planets(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Planets[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Planets[i][j] > Planets[i][k] + Planets[k][j])
                {
                    Planets[i][j] = Planets[i][k] + Planets[k][j];
                }
            }
        }
    }

    dfs(S, 0, 0, Planets);
    cout << ans;

    return 0;
}