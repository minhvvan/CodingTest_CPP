#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, D;
vector<vector<int>> children;
vector<bool> visited;
int ans = 0;

int main()
{
    INPUT_OPTIMIZE;

	cin >> N;
	children.resize(N, vector<int>());
	visited.resize(N, false);
	int root = -1;

	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;

		if (p == -1)
		{
			root = i;
			continue;
		}

		children[p].push_back(i);
	}

	cin >> D;
	children[D].clear();
	
	if (D == root)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(root);

	while (!q.empty())
	{
		auto current = q.front();
		q.pop();
		if (current == D) continue;

		if (visited[current]) continue;
		if (children[current].empty())
		{
			ans++;
			continue;
		}

		visited[current] = true;

		if (children[current].size() == 1 && children[current][0] == D)
		{
			ans++;
			continue;
		}

		for (auto child : children[current])
		{
			q.push(child);
		}
	}

	cout << ans;

	return 0;
} 