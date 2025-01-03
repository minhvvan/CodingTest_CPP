#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<int>> board;

vector<int> dy = { -1, 0, 1, 0, -1, -1, 1, 1 };
vector<int> dx = { 0, 1, 0, -1, -1, 1, 1, -1 };
vector<vector<bool>> mountain;

int ans = 0;
void bfs(int i, int j)
{
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	vector<pair<int, int>> sameHeight;

	int height = board[i][j];
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		if (visited[y][x]) continue;
		visited[y][x] = true;

		for (int i = 0; i < 8; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;

			if (height < board[newY][newX]) return;
			else if (height > board[newY][newX]) continue;

			if (visited[newY][newX]) continue;
			if (board[newY][newX] == 0) continue;

			sameHeight.push_back({ newY, newX });
			q.push({ newY, newX });
		}
	}

	for (auto [y, x] : sameHeight)
	{
		mountain[y][x] = true;
	}

	ans++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	board.resize(N, vector<int>(M));
	mountain.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0) continue;
			if (mountain[i][j]) continue;
			bfs(i, j);
		}
	}

	cout << ans;

	return 0;
}