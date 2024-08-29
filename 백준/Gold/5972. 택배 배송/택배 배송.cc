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
#include <list>
#include <bitset>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> loads;

int dijk()
{
    //1 -> N
    vector<int> result(N + 1, INT_MAX);
    result[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();

        if (result[node] < -dist) continue;

        for (auto [next, cost] : loads[node])
        {
            if (result[next] > result[node] + cost)
            {
                result[next] = result[node] + cost;
                pq.push({ -result[node], next });
            }
        }
    }

    return result[N];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    loads.resize(N+1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        loads[a].push_back({ b,c });
        loads[b].push_back({ a,c });
    }

    cout << dijk();

    return 0;
}