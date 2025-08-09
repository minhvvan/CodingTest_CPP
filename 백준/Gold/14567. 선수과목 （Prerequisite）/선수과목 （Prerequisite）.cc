#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<int> counts;
vector<int> ans;
vector<vector<int>> adj;


int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> M;

	counts.resize(N + 1, 0);
	ans.resize(N + 1, MAX);
	adj.resize(N + 1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		counts[b]++;
		adj[a].push_back(b);
	}


	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (counts[i] == 0)
		{
			q.push(i);
		}
	}


	int round = 1;
	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			auto node = q.front();
			q.pop();

			if (ans[node] != MAX) continue;
			ans[node] = round;

			for (auto next : adj[node])
			{
				if (--counts[next] == 0)
				{
					q.push(next);
				}
			}
		}

		round++;
	}


	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}