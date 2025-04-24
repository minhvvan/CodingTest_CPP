#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, N;
vector<int> graph;
vector<bool> visited;
int cnt = 0;

void DetectCycle(int current)
{
    if (visited[current])
    {
        //cycle
        cnt++;
        return;
    }

    visited[current] = true;
    DetectCycle(graph[current]);
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> T;
    while (T--)
    {
        cin >> N;
        graph.resize(N + 1);
        visited.resize(N + 1);

        for (int i = 1; i <= N; i++)
        {
            cin >> graph[i];
            visited[i] = false;
        }

        cnt = 0;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i]) continue;
            DetectCycle(i);
        }

        cout << cnt << "\n";
    }

    return 0;
} 