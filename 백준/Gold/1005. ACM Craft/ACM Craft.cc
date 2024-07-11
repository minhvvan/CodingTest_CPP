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

int T, N, K;

vector<int> inDegree;
vector<int> Costs;
vector<vector<int>> graph;
vector<int> result;

void TopologySort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if(inDegree[i]== 0)
        {
            q.push(i);
            result[i] = Costs[i];
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        if (q.empty())   return;
        auto cur = q.front();
        q.pop();

        for (auto next : graph[cur])
        {
            result[next] = max(result[next], result[cur] + Costs[next]);

            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T-- > 0)
    {
        cin >> N >> K;

        graph.assign(N + 1, vector<int>());
        inDegree.assign(N + 1, 0);
        Costs.assign(N + 1, 0);
        result.assign(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            cin >> Costs[i];
        }

        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            inDegree[b]++;
        }

        int Target;
        cin >> Target;

        TopologySort();

        cout << result[Target] << "\n";
    }

    return 0;
}