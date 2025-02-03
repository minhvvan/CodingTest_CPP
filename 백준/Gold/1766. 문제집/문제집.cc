#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> orders;
vector<int> inDegree;

void Topology()
{
	priority_queue<int> pq;

	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0) pq.push(-i);
	}

	while (!pq.empty())
	{
		int current = -pq.top();
		pq.pop();

		cout << current << " ";

		for (auto next : orders[current])
		{
			inDegree[next]--;
			if(inDegree[next] == 0) pq.push(-next);
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

	orders.resize(N + 1);
	inDegree.resize(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		orders[a].push_back(b);
		inDegree[b]++;
	}

	Topology();

	return 0;
}