#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
int S, E;
vector<vector<pair<int, int>>> adj;
vector<int> dp;
vector<int> prevNode;

void Print(int n, vector<int>& nodes)
{
	nodes.push_back(n);

	if (n == prevNode[n]) return;
	Print(prevNode[n], nodes);
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	adj.resize(N + 1, vector<pair<int, int>>());
	dp.resize(N + 1, MAX);
	prevNode.resize(N + 1, MAX);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
	}

	cin >> S >> E;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
	dp[S] = 0;
	prevNode[S] = S;

	while (!pq.empty())
	{
		auto [dist, current] = pq.top();
		pq.pop();

		dist *= -1;
		if (dist > dp[current]) continue;

		for (auto& [next, cost] : adj[current])
		{
			if (dp[next] > dp[current] + cost)
			{
				dp[next] = dp[current] + cost;
				prevNode[next] = current;

				pq.push({ -dp[next], next });
			}
		}
	}

	cout << dp[E] << "\n";

	vector<int> temp;
	Print(E, temp);

	cout << temp.size() << "\n";
	while (!temp.empty())
	{
		cout << temp.back() << " ";
		temp.pop_back();
	}

	return 0;
}