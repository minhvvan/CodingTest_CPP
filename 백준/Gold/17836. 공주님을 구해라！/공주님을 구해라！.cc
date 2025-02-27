#include <bits/stdc++.h>

using namespace std;

int N, M, T;
vector<vector<int>> board;
const int MAX = 987'654'321;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int Bfs(int sy, int sx, int ey, int ex, bool hasSword)
{
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	q.push({ sy, sx });
	visited[sy][sx] = true;
	int time = 0;

	while (!q.empty())
	{
		if (time >= T) break;
		int size = q.size();
		for (int t = 0; t < size; t++)
		{
			auto [y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY == ey && newX == ex)
				{
					return time + 1;
				}

				if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
				if (visited[newY][newX]) continue;
				if (!hasSword && board[newY][newX] == 1) continue;

				visited[newY][newX] = true;
				q.push({ newY, newX });
			}
		}

		time++;
	}

	return MAX;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N >> M >> T;
	board.resize(N, vector<int>(M));

	pair<int, int> sword;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2) sword = { i,j };
		}
	}

	//(0, 0) -> (N, M)
	int noSword = Bfs(0, 0, N - 1, M - 1, false);

	//(0, 0) -> sword -> (N, M)
	int Sword = Bfs(0, 0, sword.first, sword.second, false) + Bfs(sword.first, sword.second, N - 1, M - 1, true);

	int ans = min(noSword, Sword);
	if (ans <= T) cout << ans;
	else cout << "Fail";

	return 0;
}