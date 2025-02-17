#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> roads;
long long cost = 0;

void Prim()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });

	vector<bool> visited(M, false);

	while (!pq.empty())
	{
		auto [dist, current] = pq.top();
		pq.pop();

		if (visited[current]) continue;
		visited[current] = true;

		dist *= -1;
		cost += dist;

		for (auto [next, nextDist] : roads[current])
		{
			pq.push({ -nextDist, next });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;


	while (true)
	{
		cin >> M >> N;
		if (M == 0 && N == 0) break;

		roads.clear();
		cost = 0;
		roads.resize(M);

		long long total = 0;
		for (int i = 0; i < N; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			roads[a].push_back({ b,c });
			roads[b].push_back({ a,c });

			total += c;
		}

		Prim();

		cout << total - cost << "\n";
	}

	return 0;
}