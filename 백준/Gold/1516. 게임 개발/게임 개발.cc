#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj;
vector<int> costs;
vector<int> inDgree;
vector<int> ans;

void Topology()
{
	priority_queue<pair<int,int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (inDgree[i] == 0)
		{
			pq.push({ -costs[i], i });
			ans[i] = costs[i];
		}
	}

	while (!pq.empty())
	{
		auto [cost, current] = pq.top();
		pq.pop();

		cost *= -1;

		for (auto next : adj[current])
		{
			inDgree[next]--;
			if (inDgree[next] == 0)
			{
				ans[next] = max(ans[next] ,ans[current] + costs[next]);
				pq.push({ -ans[next], next });
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

	cin >> N;

	adj.resize(N + 1, vector<int>());
	inDgree.resize(N + 1, 0);
	costs.resize(N + 1, 0);
	ans.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> costs[i];
		
		while (true)
		{
			int prev;
			cin >> prev;

			if (prev == -1) break;
			adj[prev].push_back(i);
			inDgree[i]++;
		}
	}

	Topology();

	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}