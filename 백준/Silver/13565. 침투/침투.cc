#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int M, N;
vector<vector<int>> board;
vector<vector<bool>> visited;

vector<int> dy = { 1, 0, -1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> M >> N;
	board.resize(M, vector<int>(N));
	visited.resize(M, vector<bool>(N, false));

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	for (int j = 0; j < N; j++)
	{
		if (board[0][j] == 0)
		{
			q.push({ 0, j });
			visited[0][j] = true;
		}
	}

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= M || newX < 0 || newX >= N) continue;
			if (visited[newY][newX]) continue;
			if (board[newY][newX] == 1) continue;
			if (newY == M - 1)
			{
				cout << "YES";
				return 0;
			}

			visited[newY][newX] = true;
			q.push({ newY, newX });
		}
	}

	cout << "NO";

	return 0;
}