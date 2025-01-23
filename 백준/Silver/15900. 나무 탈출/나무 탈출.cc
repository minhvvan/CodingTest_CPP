#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> tree;
vector<int> childDepth;
vector<bool> visited;

int dfs(int node, int depth)
{
	visited[node] = true;

	if (tree[node].size() == 1 && visited[tree[node][0]])
	{
		visited[node] = true;
		return childDepth[node] = depth;
	}

	for (auto next : tree[node])
	{
		if (visited[next]) continue;

		childDepth[node] += dfs(next, depth+1);
	}

	return childDepth[node];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	tree.resize(N+1);
	childDepth.resize(N+1, 0);
	visited.resize(N+1, false);

	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

    dfs(1, 0);

	int cnt = 0;
	for (auto next : tree[1])
	{
		cnt += childDepth[next];
	}

	if (cnt % 2 == 1) cout << "Yes";
	else cout << "No";

	return 0;
}