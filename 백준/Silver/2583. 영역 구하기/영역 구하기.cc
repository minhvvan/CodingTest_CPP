#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> board;
vector<vector<bool>> visited;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

vector<int> ans;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	int cnt = 0;
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (visited[newY][newX]) continue;
			if (board[newY][newX] == 1) continue;

			visited[newY][newX] = true;
			q.push({ newY,newX });
		}
	}

	ans.push_back(cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M >> K;
	board.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));

	/*
	* 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이
	*/
	for (int t = 0; t < K; t++)
	{
		int ly, lx, ry, rx;
		cin >> lx >> ly >> rx >> ry;

		for (int i = ly; i < ry; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0 && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto cnt : ans)
	{
		cout << cnt << " ";
	}

	return 0;
}