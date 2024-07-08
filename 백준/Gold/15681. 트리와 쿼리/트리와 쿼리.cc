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

int N, R, Q;

vector<int> SubTree;
vector<int> link;
vector<bool> visited;

void DFS(vector<vector<int>>& edges, int node)
{
    int ans = 1;

    for (auto next : edges[node])
    {
        if (visited[next]) continue;
        visited[next] = true;

        DFS(edges, next);
        ans += SubTree[next];
    }

    SubTree[node] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;

    SubTree.resize(N + 1, 0);
    visited.resize(N + 1, false);
    vector<vector<int>> edges(N+1);

    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[R] = true;
    DFS(edges, R);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << SubTree[q] << "\n";
    }

    return 0;
}