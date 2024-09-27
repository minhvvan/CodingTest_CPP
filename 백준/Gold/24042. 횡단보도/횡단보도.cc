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

int N, M;
vector<vector<pair<int, int>>> crosses;
vector<long long> Dist;

void dijk()
{
    priority_queue<pair<long long, int>> pq;
    pq.push({ 0, 1 });
    Dist[1] = 0;

    while (!pq.empty())
    {
        auto [dist, current] = pq.top();
        pq.pop();

        dist *= -1;

        for (auto& [next, nextDist] : crosses[current])
        {
            long long passTime = nextDist;
            if (nextDist < dist)
            {
                long long cycle = (dist - nextDist) / M;
                if ((dist - nextDist) % M != 0) cycle++;
                passTime = cycle * M + nextDist;
            }
                
            if (passTime < Dist[next])
            {
                Dist[next] = passTime;
                pq.push({ -Dist[next], next });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    crosses.resize(N+1);
    Dist.resize(N+1, LLONG_MAX);

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;

        crosses[a].push_back({ b, i });
        crosses[b].push_back({ a, i });
    }

    dijk();
    cout << Dist[N];

    return 0;
}