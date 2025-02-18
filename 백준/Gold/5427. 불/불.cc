#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

vector<vector<char>> board;
vector<vector<bool>> visited;
queue<pair<int, int>> player;

void Move(int cnt)
{
	while (!player.empty())
	{
		int size = player.size();

		for (int p = 0; p < size; p++)
		{
			auto [y, x] = player.front();
			player.pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY < 0 || newY >= N || newX < 0 || newX >= M)
				{
					cout << cnt + 1 << "\n";
					return;
				}
				if (board[newY][newX] == '*' || board[newY][newX] == '#') continue;
				if (visited[newY][newX]) continue;
				visited[newY][newX] = true;

				player.push({ newY, newX });
			}
		}

		cnt++;
	}

	cout << "IMPOSSIBLE\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T;

	while (T--)
	{
		cin >> M >> N;

		board.clear();
		visited.clear();
		while (!player.empty()) player.pop();

		board.resize(N, vector<char>(M));
		visited.resize(N, vector<bool>(M, false));

		pair<int, int> pos;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < M; j++)
			{
				board[i][j] = str[j];
				if (board[i][j] == '@')
				{
					pos = { i, j };
				}
				if (board[i][j] == '*')
				{
					q.push({ i,j });
				}
			}
		}
		
		player.push(pos);
		visited[pos.first][pos.second] = true;

		int cnt = 0;
		bool flag = false;
		while (!q.empty())
		{
			int size = q.size();

			for (int t = 0; t < size; t++)
			{
				auto [y, x] = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int newY = y + dy[i];
					int newX = x + dx[i];

					if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
					if (board[newY][newX] == '*' || board[newY][newX] == '#') continue;

					board[newY][newX] = '*';
					q.push({ newY, newX });
				}
			}

			int playerSize = player.size();

			for(int p = 0 ; p < playerSize; p++)
			{
				auto [y, x] = player.front();
				player.pop();

				for (int i = 0; i < 4; i++)
				{
					int newY = y + dy[i];
					int newX = x + dx[i];

					if (newY < 0 || newY >= N || newX < 0 || newX >= M)
					{
						//탈출
						cout << cnt + 1 << "\n";
						flag = true;
						break;
					}
					if (board[newY][newX] == '*' || board[newY][newX] == '#') continue;
					if (visited[newY][newX]) continue;
					visited[newY][newX] = true;

					player.push({ newY, newX });
				}

				if (flag) break;
			}

			if (flag) break;
			cnt++;
		}

		if(!flag) Move(cnt);
	}

	return 0;
}