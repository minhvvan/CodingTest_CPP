#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> board;
const int MAX = 987654321;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	board.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	deque<tuple<int, int, int>> dq;
	vector<vector<int>> visited(N, vector<int>(M, MAX));
	dq.push_back({ 0, 0, 0 });
	visited[0][0] = 0;

	while (!dq.empty())
	{
		auto [y, x, cost] = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (visited[newY][newX] <= cost) continue;

			if (board[newY][newX] == 1)
			{
				if (visited[newY][newX] <= cost + 1) continue;

				visited[newY][newX] = cost + 1;
				dq.push_back({ newY,newX, cost + 1 });
			}
			else
			{
				visited[newY][newX] = cost;
				dq.push_front({ newY,newX, cost });
			}
		}
	}

	cout << visited[N - 1][M - 1];

	return 0;
}