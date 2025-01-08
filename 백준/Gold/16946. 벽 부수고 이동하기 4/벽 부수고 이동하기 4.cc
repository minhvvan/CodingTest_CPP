#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> dp;
vector<int> sizes;
vector<vector<bool>> visited;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void Bfs(int i, int j, int idx)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	int size = 0;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		if (visited[y][x]) continue;
		visited[y][x] = true;
		size++;
		dp[y][x] = idx;

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (visited[newY][newX]) continue;
			if (board[newY][newX] == 1) continue;

			q.push({ newY,newX });
		}
	}

	sizes.push_back(size);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;
	board.resize(N, vector<int>(M));
	dp.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));
	sizes.push_back(-1);

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = input[j] - '0';
		}
	}

	//덩어리 만들고 상하좌우 더하기
	int idx = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]) continue;
			if (board[i][j] == 1) continue;
			Bfs(i, j, idx++);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				cout << 0;
				continue;
			}

			unordered_set<int> near;
			int ans = 0;
			for (int k = 0; k < 4; k++)
			{
				int newY = i + dy[k];
				int newX = j + dx[k];

				if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
				if (dp[newY][newX] == 0) continue;

				near.insert(dp[newY][newX]);
			}

			for (auto nearBlock : near)
			{
				ans += sizes[nearBlock];
			}

			cout << (ans + 1) % 10;
		}

		cout << "\n";
	}

	return 0;
}