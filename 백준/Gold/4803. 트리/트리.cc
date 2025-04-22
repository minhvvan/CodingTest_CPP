#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;

vector<vector<int>> graph;
vector<bool> visited;

bool Dfs(int start, int prev)
{
    visited[start] = true;
    for (auto node : graph[start])
    {
        if (node == prev) continue;

        if (visited[node]) return false;
        if (!Dfs(node, start)) return false;
    }

    return true;
}

int main() 
{
    INPUT_OPTIMIZE;

    int t = 1;
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        graph.resize(N + 1, vector<int>());
        visited.resize(N + 1);

        for (int i = 1; i <= N; i++)
        {
            graph[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (visited[i]) continue;
            if (Dfs(i, 0)) cnt++;
        }

        if (cnt > 1)
        {
            cout << "Case " << t++ << ": A forest of " << cnt << " trees.\n";

        }
        else if (cnt == 1)
        {
            cout << "Case " << t++ << ": There is one tree.\n";

        }
        else
        {
            cout << "Case " << t++ << ": No trees.\n";
        }
    }

    return 0;
} 