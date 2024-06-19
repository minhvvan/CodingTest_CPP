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

int N, M, K;
const int MAX = 10'000 * 10'000 + 1;

int Djik(vector<vector<tuple<int, int, int>>>& adj)
{
    //next, costSum, timeSum
    queue<tuple<int, int, int>> pq;
    vector<vector<int>> dist(N + 1, vector<int>(M+1, MAX));
    int ans = MAX;

    for(int j = 0; j <= M; j++) dist[1][j] = 0;
    pq.push({ 0, 0, 1 });

    while (!pq.empty())
    {
        auto [time, cost, current] = pq.front();
        pq.pop();

        cost *= -1;
        time *= -1;
        if (dist[current][cost] < time) continue;

        for (auto [next, c, d] : adj[current])
        {
            if (cost + c > M) continue;
            int totalCost = cost + c;

            if (dist[next][totalCost] > dist[current][cost] + d)
            {
                dist[next][totalCost] = dist[current][cost] + d;
                if (next == N)
                {
                    ans = min(ans, dist[next][totalCost]);
                    continue;
                }

                pq.push({ -dist[next][totalCost], -totalCost, next});
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        cin >> N >> M >> K;

        vector<vector<tuple<int, int, int>>> adj(N+1);

        for (int i = 0; i < K; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;

            adj[u].push_back({ v, c, d });
        }

        int ans = Djik(adj);
        if (ans == MAX) cout << "Poor KCM\n";
        else cout << ans;
    }
 
    return 0;
}