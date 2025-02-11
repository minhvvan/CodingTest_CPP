#include <bits/stdc++.h>

using namespace std;

int T, N, M, W;
struct Edge
{
	int start;
	int end;
	int dist;
};

vector<Edge> edges;

void bellman()
{
	vector<int> dist(N + 1, 987654321);
	dist[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (auto edge : edges)
		{
			int from = edge.start;
			int to = edge.end;
			int cost = edge.dist;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (auto edge : edges)
	{
		int from = edge.start;
		int to = edge.end;
		int cost = edge.dist;

		if (dist[to] > dist[from] + cost)
		{
			cout << "YES" << "\n";
			return;
		}
	}

	cout << "NO" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T;

	while (T--)
	{
		cin >> N >> M >> W;
		edges.clear();

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edges.push_back({ a,b,c });
			edges.push_back({ b,a,c });
		}

		for (int i = 0; i < W; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edges.push_back({ a,b,-c });
		}

		bellman();
	}
	
	return 0;
}