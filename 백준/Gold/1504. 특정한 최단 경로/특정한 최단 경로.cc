#include <bits/stdc++.h>

using namespace std;

int N, E;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> dist;

void Dijk(int start, int end)
{
    dist[start][start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto [cost, current] = pq.top();
        pq.pop();

        cost *= -1;
        if (cost > dist[start][current]) continue;

        for (auto& [next, d] : adj[current])
        {
            if (dist[start][next] > dist[start][current] + d)
            {
                dist[start][next] = dist[start][current] + d;
                pq.push({ -dist[start][next], next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  
    
    cin >> N >> E;

    const int MAX = 987654321;
    dist.resize(N + 1, vector<int>(N + 1, MAX));
    adj.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    vector<int> Points(2);
    cin >> Points[0];
    cin >> Points[1];

    //1 -> points;
    Dijk(1, Points[0]);
    Dijk(1, Points[1]);

    if (dist[1][Points[0]] >= MAX || dist[1][Points[0]] >= MAX)
    {
        cout << -1;
        return 0;
    }

    //points -> points
    Dijk(Points[1], Points[0]);
    Dijk(Points[0], Points[1]);

    if (dist[Points[0]][Points[1]] >= MAX || dist[Points[1]][Points[0]] >= MAX)
    {
        cout << -1;
        return 0;
    }

    //points -> N
    Dijk(Points[1], N);
    Dijk(Points[0], N);

    if (dist[Points[0]][N] >= MAX || dist[Points[1]][N] >= MAX)
    {
        cout << -1;
        return 0;
    }

    int ans = min(dist[1][Points[0]] + dist[Points[0]][Points[1]] + dist[Points[1]][N], dist[1][Points[1]] + dist[Points[1]][Points[0]] + dist[Points[0]][N]);
    if (ans > MAX) cout << -1;
    else cout << ans;

    return 0;
}