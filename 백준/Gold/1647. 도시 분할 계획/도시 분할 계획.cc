#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> roads;
vector<int> included;

void MST()
{
	priority_queue<pair<int, int>> pq;
	vector<bool> visited(N + 1, false);
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		auto [dist, current] = pq.top();
		pq.pop();

		if (visited[current]) continue;
		visited[current] = true;
		included.push_back(-dist);

		for (auto [next, cost] : roads[current])
		{
			if (visited[next]) continue;
			pq.push({ -cost, next });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	roads.resize(N + 1, vector<pair<int, int>>());

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		roads[a].push_back({ b,c });
		roads[b].push_back({ a,c });
	}

	MST();
	sort(included.begin(), included.end());


	int ans = 0;
	for (int i = 0; i < included.size() - 1; i++)
	{
		ans += included[i];
	}

	cout << ans;

	return 0;
}