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
#include <set>
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<vector<int>> Nums(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Nums[i][j];
        }
    }

    priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq;
    for (int i = 0; i < N; i++)
    {
        pq.push({ Nums[N - 1][i], N - 1, i });
    }

    for (int i = 0; i < N-1; i++)
    {
        auto [num, y, x] = pq.top();
        pq.pop();
        if (y == 0) continue;

        pq.push({ Nums[y - 1][x], y - 1, x });
    }

    auto [ans, y, x] = pq.top();
    cout << ans;

    return 0;
}