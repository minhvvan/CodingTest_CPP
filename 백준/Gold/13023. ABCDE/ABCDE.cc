#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<int>> adj;
unordered_set<int> inStack;

bool DFS(int current)
{
	if (inStack.size() == 5)
	{
		cout << 1;
		return true;
	}

	for (auto next : adj[current])
	{
		if (inStack.count(next)) continue;

		inStack.insert(next);
		auto flag = DFS(next);
		inStack.erase(next);

		if (flag) return true;
	}

	return false;
}

int main()
{
    INPUT_OPTIMIZE;

	cin >> N >> M;
	adj.resize(N, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		inStack.insert(i);

		if (DFS(i))
		{
			flag = true;
			break;
		}
		inStack.erase(i);
	}

	if (!flag)
	{
		cout << 0;
	}

	return 0;
} 