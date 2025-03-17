#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> edges;
vector<bool> visited;
int cnt;

void Dfs(int start)
{
	visited[start] = true;
	
	for (auto next : edges[start])
	{
		if (visited[next]) continue;

		cnt++;
		Dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	edges.resize(N + 1, vector<int>());
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[b].push_back(a);
	}

	/*
	* b를 해킹하면 a를 해킹할 수 있다.
	*/

	int max = 0;
	vector<int> answers;

	for (int i = 1; i <= N; i++)
	{
		for (int i = 1; i <= N; i++) visited[i] = false;
		cnt = 0;
		Dfs(i);

		if (max < cnt)
		{
			max = cnt;
			answers.clear();
			answers.push_back(i);
		}
		else if (max == cnt)
		{
			answers.push_back(i);
		}
	}

	for (auto ans : answers)
	{
		cout << ans << " ";
	}

	return 0;
}