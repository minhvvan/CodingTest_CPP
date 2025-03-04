#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<bool>> adj;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N;

	adj.resize(N, vector<bool>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			adj[i][j] = a == 1 ? true : false;
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (adj[i][k] && adj[k][j])
				{
					adj[i][j] = adj[i][k] && adj[k][j];
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j]) cout << 1 << " ";
			else cout << 0 << " ";
		}

		cout << "\n";
	}

	return 0;
}