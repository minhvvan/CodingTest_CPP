#include <bits/stdc++.h>

using namespace std;

int N, M, x, y;
vector<vector<pair<int, int>>> edges;
vector<long long> dists;
vector<long long> moveCnt;
const int DIV = 1'000'000'009;
const long long INF = 600'000'000'001;

void Dijk()
{
    vector<bool> visited(N + 1, false);
    priority_queue<tuple<long long, int>> pq;
    pq.push({ 0, x });
    dists[x] = 0;

    while (!pq.empty())
    {
        auto [dist, current] = pq.top();
        pq.pop();

        dist *= -1;
        if (dist > dists[current]) continue;

        for (auto [next, cost] : edges[current])
        {
            if (dists[next] <= dist + cost) continue;

            dists[next] = dists[current] + cost;
            pq.push({ -dists[next], next});
        }
    }
}

void findMoveCnt()
{
    queue<int>q; 
    q.push(x);

    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (auto [next, cost] : edges[cur]) 
        {
            if (dists[next] != dists[cur] + cost) continue;
            if (!moveCnt[next])
            {
                moveCnt[next] = moveCnt[cur] + 1;
                q.push(next);
            }
        }
    }
}

//long long findPath(int current)
//{
//    if (current == y) return 1;
//
//    long long result = 0;
//    for (auto [next, cost] : edges[current])
//    {
//        if (moveCnt[next] == moveCnt[current] + 1 && dists[next] == dists[current] + cost)
//        {
//            result += findPath(next);
//            result %= DIV;
//        }
//    }
//
//    return result;
//}

long long dp[100005];
long long f(int cur) {
    long long& ret = dp[cur];
    if (~ret) return ret;
    ret = 0;
    for (auto [nxt, cost] : edges[cur]) {
        if (moveCnt[nxt] == moveCnt[cur] + 1 && dists[nxt] == dists[cur]+cost) ret += f(nxt);
    }

    return ret %= DIV;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M >> x >> y;

    edges.resize(N + 1);
    dists.resize(N + 1, INF);
    moveCnt.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges[u].push_back({ v,w });
    }

    Dijk();

    if (dists[y] == INF)
    {
        cout << -1;
        return 0;
    }

    findMoveCnt();
    memset(dp, -1, sizeof(dp));
    dp[y] = 1;
    cout << dists[y] << "\n" << moveCnt[y] << "\n" << f(x);

    return 0;
}