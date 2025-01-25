#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;
vector<vector<int>> roads;
vector<long long> dist;

void dijk()
{
	queue<pair<int, long long>> q;
	dist[X] = 0;
	q.push({X, 0});

	while (!q.empty())
	{
		auto [current, cost] = q.front();
		q.pop();

		for (auto next : roads[current])
		{
			if (cost + 1 < dist[next])
			{
				dist[next] = cost + 1;
				q.push({next, dist[next]});
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

	cin >> N >> M >> K >> X;

	roads.resize(N+1);
	dist.resize(N+1, LLONG_MAX);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		roads[a].push_back(b);
	}

	dijk();

	vector<int> ans;
	for (int i = 1 ; i <= N; i++)
	{
		if (dist[i] == K) ans.push_back(i);
	}

	if (ans.size() == 0) cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (auto a : ans)
		{
			cout << a << "\n";
		}
	}

	return 0;
}