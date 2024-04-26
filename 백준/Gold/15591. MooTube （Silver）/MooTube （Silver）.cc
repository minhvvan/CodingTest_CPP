#include <stdio.h>
#include <vector>
#include <climits>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int BFS(int K, int V, int N, vector<vector<pair<int, int>>>& graph)
{
	queue<pair<int, int>> q;
	vector<bool> visited(N + 1, false);
	vector<int> usado(N + 1, INT_MAX);

	q.push({ V, 0 });
	visited[V] = true;
	usado[V] = 0;

	for (auto [next, nextUsado] : graph[V])
	{
		q.push({ next, nextUsado });
		usado[next] = nextUsado;
		visited[next] = true;
	}

	while (!q.empty())
	{
		auto [node, currentUsado] = q.front();
		q.pop();

		for (auto [nextNode, nextUsado] : graph[node])
		{
			if (visited[nextNode]) continue;

			visited[nextNode] = true;
			usado[nextNode] = min(currentUsado, nextUsado);
			q.push({ nextNode, usado[nextNode] });
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (usado[i] >= K) cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<vector<pair<int,int>>> graph(N+1);

	for (int i = 0; i < N - 1; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;

		graph[p].push_back({ q, r });
		graph[q].push_back({ p, r });
	}

	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;

		cout << BFS(k, v, N, graph) << "\n";
	}

	return 0;
}