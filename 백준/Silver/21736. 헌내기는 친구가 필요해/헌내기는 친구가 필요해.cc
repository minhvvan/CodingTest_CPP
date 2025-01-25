#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> campus;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	campus.resize(N, vector<char>(M));
	pair<int, int> pos;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			campus[i][j] = str[j];
			if (str[j] == 'I') pos = { i, j };
		}
	}

	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	q.push(pos);
	visited[pos.first][pos.second] = true;

	vector<int> dy = { -1, 0, 1, 0 };
	vector<int> dx = { 0, 1, 0, -1 };

	int ans = 0;
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (campus[newY][newX] == 'X') continue;
			if (visited[newY][newX]) continue;
			visited[newY][newX] = true;

			if (campus[newY][newX] == 'P') ans++;
			q.push({ newY, newX });
		}
	}

	if (ans == 0) cout << "TT";
	else cout << ans;

	return 0;
}