#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<string> board;
vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int sheep = 0;
int wolf = 0;

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	int w = 0, s = 0;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (visited[newY][newX]) continue;
			if (board[newY][newX] == '#') continue;

			if (board[newY][newX] == 'v') w++;
			else if (board[newY][newX] == 'k') s++;

			visited[newY][newX] = true;
			q.push({ newY, newX });
		}
	}

	if (w < s) wolf -= w;
	else sheep -= s;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	board.resize(N);
	visited.resize(N,vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];

		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'v') wolf++;
			else if (board[i][j] == 'k') sheep++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]) continue;

			visited[i][j] = true;
			BFS(i, j);
		}
	}

	cout << sheep << " " << wolf;

	return 0;
}