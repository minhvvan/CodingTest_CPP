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

int N, M, X;
vector<vector<pair<int, int>>> roads;
vector<vector<int>> result;
const int MAX = 1000 * 100 + 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    roads.resize(N + 1);
    result.resize(N + 1, vector<int>(N + 1, MAX));
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a].push_back({ b, c });
        result[a][b] = c;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == X) continue;
        ans = max(ans, result[i][X] + result[X][i]);
    }

    cout << ans;

    return 0;
}