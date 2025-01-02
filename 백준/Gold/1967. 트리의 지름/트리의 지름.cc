#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<pair<int,int>>> edges;

pair<int, int> Bfs(int start)
{
    queue<pair<int, int>> q;
    vector<int> visited(N + 1, -1);
    q.push({start, 0});
    pair<int, int> result = {start, -1};

    while (!q.empty())
    {
        auto [current, cost] = q.front();
        q.pop();

        if (cost <= visited[current]) continue;
        visited[current] = cost;
        if (result.second < cost)
        {
            result = { current, cost };
        }

        for (auto [next, dist] : edges[current])
        {
            if (visited[next] != -1) continue;
            q.push({ next, cost + dist });
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> N;

    edges.resize(N + 1);
    for (int i = 0; i < N-1; i++)
    {
        int p, c, d;
        cin >> p >> c >> d;

        edges[p].push_back({ c, d });
        edges[c].push_back({ p, d });
    }
      
    auto [farNode, dist] = Bfs(1);
    auto [ansNode, ans] = Bfs(farNode);

    cout << ans;
    
    return 0;
}