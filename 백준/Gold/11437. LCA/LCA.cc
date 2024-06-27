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

int N, M;
const int MAX = 50'001;
bool visited[MAX];

void dfs(vector<vector<int>>& adj, vector<pair<int, int>>& log, int node, int depth)
{
    log.push_back({ node, depth });

    for (auto next : adj[node])
    {
        if (visited[next]) continue;
        visited[next] = true;

        dfs(adj, log, next, depth+1);
        log.push_back({ node, depth });
    }
}

int findLCA(vector<vector<int>>& adj, vector<pair<int, int>>& log, int a, int b)
{
    int start = 0, end = 0;
    for (int i = 0; i < log.size(); i++)
    {
        if (log[i].first == a)
        {
            start = i;
            break;
        }
    }

    for (int i = 0; i < log.size(); i++)
    {
        if (log[i].first == b)
        {
            end = i;
            break;
        }
    }

    if (start > end) swap(start, end);
    int ans = 1;
    int minDepth = MAX;
    for (int i = start; i <= end; i++)
    {
        if (log[i].second < minDepth)
        {
            minDepth = log[i].second;
            ans = log[i].first;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> adj(N+1);
    vector<int> depth(N + 1, 1);

    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> log;
    visited[1] = true;
    dfs(adj, log, 1, 1);

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << findLCA(adj, log, a, b) << "\n";
    }

    return 0;
}