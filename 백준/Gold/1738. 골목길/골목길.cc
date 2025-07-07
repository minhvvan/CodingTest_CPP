#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<tuple<int, int, int>> edges;
vector<vector<int>> revAdj;
vector<bool> visited;
vector<int> dist;
vector<int> pre;


void CheckReach()
{
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		auto current = q.front();
		q.pop();

		if (visited[current]) continue;
		visited[current] = true;

		for (auto& next : revAdj[current])
		{
			if (visited[next]) continue;
			q.push(next);
		}
	}
}

void print(int n) {

	if (n == 0) return;
	print(pre[n]);
	cout << n << ' ';
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;
	
	revAdj.resize(N + 1, vector<int>());
	visited.resize(N + 1, false);
	dist.resize(N + 1, MAX);
	pre.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		revAdj[b].push_back(a);
		edges.push_back({ a,b,-c });
	}

	CheckReach();

	if (!visited[1]) 
	{
		cout << -1 << '\n';
		return 0;
	}

	dist[1] = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (auto& [a, b, c] : edges)
		{
			if (dist[b] > dist[a] + c)
			{
				dist[b] = dist[a] + c;
				pre[b] = a;
			}
		}
	}

	// check
	for (auto& [a, b, c] : edges)
	{
		if (dist[b] > dist[a] + c)
		{
			// 음수 사이클
			if (visited[a])
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	print(N);

	return 0;
}