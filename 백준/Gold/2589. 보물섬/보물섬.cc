#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> world;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int ans = 0;

void bfs(int i, int j)
{
	queue<tuple<int, int, int>> q;
	vector<vector<int>> visited(N, vector<int>(M, 0));

	q.push({ i,j,0 });
	visited[i][j] = true;

	while (!q.empty())
	{
		auto [y, x, depth] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY< 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (world[newY][newX] == 'W') continue;
			if (visited[newY][newX]) continue;

			visited[newY][newX] = true;
			ans = max(ans, depth + 1);

			q.push({ newY,newX,depth + 1 });
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;
	world.resize(N, vector<char>(M));
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			world[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (world[i][j] == 'W') continue;
			bfs(i, j);
		}
	}
	
	cout << ans;

	return 0;
}