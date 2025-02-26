#include <bits/stdc++.h>

using namespace std;

int N, M;
int S, E;
vector<vector<pair<int, int>>> roads;

bool Bfs(int weight)
{
	queue<int> q;
	q.push(S);

	vector<bool> visited(N + 1, false);
	visited[S] = true;

	while (!q.empty())
	{
		auto current = q.front();
		q.pop();

		for (auto [next, cost] : roads[current])
		{
			if (visited[next]) continue;
			if (cost < weight) continue;
			if (next == E) return true;

			visited[next] = true;
			q.push(next);
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N >> M;
	roads.resize(N + 1, vector<pair<int, int>>());

	int left = 0;
	int right = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		roads[a].push_back({ b,c });
		roads[b].push_back({ a,c });
		right = max(right, c);
	}

	cin >> S >> E;

	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (Bfs(mid))
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}