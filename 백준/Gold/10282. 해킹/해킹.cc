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

using namespace std;

int T, N, D, C;

struct cmp
{
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

void BFS(vector<vector<pair<int, int>>>& adj)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
    vector<bool> visited(N + 1, false);
    pq.push({ C, 0 });

    int time = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        auto [computer, sec] = pq.top();
        pq.pop();

        if (visited[computer]) continue;
        visited[computer] = true;

        time = max(time, sec);
        cnt++;

        for (auto [next, s] : adj[computer])
        {
            pq.push({ next, sec+s });
        }
    }

    cout << cnt << " " << time << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T-- > 0)
    {
        cin >> N >> D >> C;
        vector<vector<pair<int,int>>> adj(N + 1);
        
        for (int i = 0; i < D; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;

            adj[b].push_back({ a,s });
        }

        BFS(adj);
    }

    return 0;
}