#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> visible;
vector<vector<pair<int, int>>> roads;
vector<long long> dist;
const long long MAX = 10000000001;
int ans = MAX;

void Dijk()
{
	dist[0] = 0;

	priority_queue<pair<long long, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		auto [d, current] = q.top();
		q.pop();

		d *= -1;
		if (dist[current] < d) continue;

		for (auto [next, cost] : roads[current])
		{
			if (next != N - 1 && visible[next] == 1) continue;

			if (dist[next] > dist[current] + cost)
			{
				dist[next] = dist[current] + cost;
				q.push({ -dist[next], next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	visible.resize(N, 0);
	roads.resize(N, vector<pair<int, int>>());
	dist.resize(N, MAX);

	for (int i = 0; i < N; i++)
	{
		cin >> visible[i];
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		roads[a].push_back({ b,t });
		roads[b].push_back({ a,t });
	}

	Dijk();

	if (dist[N - 1] == MAX) cout << -1;
	else cout << dist[N - 1];
	
	return 0;
}