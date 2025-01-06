#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> answer;
vector<vector<int>> adj;
const int MAX = 10000 * 1000 + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	answer.resize(N + 1, vector<int>(N + 1, 0));
	adj.resize(N + 1, vector<int>(N + 1, MAX));

	for (int i = 1; i <= N; i++)
	{
		adj[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a][b] = c;
		adj[b][a] = c;
		answer[a][b] = b;
		answer[b][a] = a;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			if (answer[i][j] == 0) cout << "- ";
			else cout << answer[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}