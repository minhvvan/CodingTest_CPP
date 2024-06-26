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

int N;
int maxDist = 0;
int maxNode = 0;

void DFS(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int start, int dist)
{
    if (visited[start]) return;

    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = start;
    }

    visited[start] = true;
    for (auto [next, cost] : adj[start])
    {
        DFS(adj, visited, next, dist + cost);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<pair<int, int>>> adj(N+1);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a;
        cin >> b;

        while (b != -1)
        {
            cin >> c;

            adj[a].push_back({ b,c });
            cin >> b;
        }
    }

    DFS(adj, visited, 1, 0);
    fill(visited.begin(), visited.end(), false);

    maxDist = 0;
    DFS(adj, visited, maxNode, 0);

    cout << maxDist;

    return 0;
}