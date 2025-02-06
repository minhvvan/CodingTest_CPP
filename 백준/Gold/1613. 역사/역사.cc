#include <bits/stdc++.h>

using namespace std;

int N, K, S;

vector<vector<int>> edges;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> K;

	edges.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;

				if (edges[i][k] + edges[k][j] == 2)
				{
					edges[i][j] = 1;
				}
			}
		}
	}


	cin >> S;

	for (int i = 0; i < S; i++)
	{
		int a, b;
		cin >> a >> b;

		//a가 먼저면 -1 b가 먼저면 1 모르면 0
		int result = edges[a][b];
		if (result == 0)
		{
			if (edges[b][a] != 0) cout << 1 << "\n";
			else cout << 0 << "\n";

			continue;
		}

		if (result > 0) 
		{
			//a->b 가능
			cout << -1 << "\n";
		}
	}

	return 0;
}