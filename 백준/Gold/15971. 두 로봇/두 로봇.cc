#include <bits/stdc++.h>

using namespace std;

int N, S, E;
vector<bool> visited;
vector<vector<pair<int, int>>> roads;
int minDist = INT_MAX;
int ans = INT_MAX;

void dfs(int current, int total, int maxCost)
{
    if (current == E)
    {
        minDist = min(minDist, total);
        ans = min(ans, minDist - maxCost);
        cout << ans;
        exit(0);
    }

    for (auto& [next, cost] : roads[current])
    {
        if (visited[next]) continue;
        visited[next] = true;

        dfs(next, total + cost, max(maxCost, cost));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> S >> E;

    visited.resize(N + 1, false);
    roads.resize(N+1);
    for (int i = 0; i < N-1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a].push_back({ b,c });
        roads[b].push_back({ a,c });
    }

    visited[S] = true;
    dfs(S, 0, 0);

    return 0;
}