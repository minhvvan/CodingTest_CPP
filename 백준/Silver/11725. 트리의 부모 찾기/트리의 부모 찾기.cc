#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> tree;
vector<int> parent;

void dfs(int current)
{
	for (auto next : tree[current])
	{
		if (parent[next] != 0) continue;
		parent[next] = current;
			
		dfs(next);
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	tree.resize(N + 1);
	parent.resize(N + 1);
	
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}