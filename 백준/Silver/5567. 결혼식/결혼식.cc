#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<int>> adj;
vector<bool> visited;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	adj.resize(N + 1, vector<int>());
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int depth = 0;
	int ans = 0;

	while (!q.empty())
	{
		if (depth > 1) break;
		int size = q.size();

		for (int k = 0; k < size; k++)
		{
			auto current = q.front();
			q.pop();

			for (auto next : adj[current])
			{
				if (visited[next]) continue;
				visited[next] = true;

				q.push(next);
				ans++;
			}
		}

		depth++;
	}


	cout << ans;

	return 0;
}