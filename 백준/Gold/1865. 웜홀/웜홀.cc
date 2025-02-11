#include <bits/stdc++.h>

using namespace std;

int T, N, M, W;
struct Edge
{
	int start;
	int end;
	int dist;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T;

	while (T--)
	{
		vector<Edge> edges;
		cin >> N >> M >> W;

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

		bool bflag = false;
		vector<bool> visited(N + 1, false);
		for (int k = 1; k <= N; k++)
		{
			vector<int> dist(N+1, INT_MAX);
			dist[k] = 0;

			if (visited[k]) continue;
			visited[k] = true;

			for (int i = 0; i < N; i++)
			{
				for (auto edge : edges)
				{
					int from = edge.start;
					int to = edge.end;
					int cost = edge.dist;

					if (dist[from] == INT_MAX) continue;
					visited[from] = true;

					if (dist[to] > dist[from] + cost)
					{
						dist[to] = dist[from] + cost;
						if (i == N - 1)
						{
							bflag = true;
							break;
						}
					}
				}
			}

			if (bflag)
			{
				cout << "YES\n";
				break;
			}
		}

		if (!bflag) cout << "NO\n";
	}
	

	return 0;
}