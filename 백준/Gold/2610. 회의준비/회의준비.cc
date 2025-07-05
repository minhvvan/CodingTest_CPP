#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<int>> dist;
vector<pair<int,int>> adj;
vector<int> maxDist;
vector<int> parent;
const int MAX = 987654321;

void CheckDistance()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;

				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int Find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (maxDist[a] > maxDist[b]) swap(a, b);
	parent[b] = a;
}


int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	maxDist.resize(N + 1, 0);
	parent.resize(N + 1);
	dist.resize(N + 1, vector<int>(N + 1, MAX));

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		adj.push_back({ a,b });
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	CheckDistance();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == MAX) continue;
			maxDist[i] = max(maxDist[i], dist[i][j]);
		}
	}

	for (auto& [a, b] : adj)
	{
		Union(a, b);
	}

	set<int> ans;
	for (int i = 1; i <= N; i++)
	{
		ans.insert(Find(i));
	}

	cout << ans.size() << "\n";
	for (auto a : ans)
	{
		cout << a << "\n";
	}
	
	return 0;
}