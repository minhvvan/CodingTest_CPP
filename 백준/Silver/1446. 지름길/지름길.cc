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

int N, D;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;

    vector<vector<pair<int, int>>> shortcuts(D);

    for (int i = 0; i < N; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;

        shortcuts[start].push_back({ end, cost });
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty())
    {
        auto [cost, current] = pq.top();
        pq.pop();

        if (current == D)
        {
            cout << cost;
            break;
        }

        if (current > D) continue;

        for (auto [end, dist] : shortcuts[current])
        {
            pq.push({ cost + dist, end });
        }

        pq.push({ cost + 1, current + 1 });
    }

    return 0;
}