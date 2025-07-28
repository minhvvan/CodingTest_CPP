#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<vector<int>> adj;
vector<vector<int>> dist;

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> M;

	adj.resize(N + 1, vector<int>());
	dist.resize(N + 1, vector<int>(N+1, MAX));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] != MAX || dist[j][i] != MAX) cnt++;
		}

		if (cnt == N - 1) ans++;
	}
	
	cout << ans;
}