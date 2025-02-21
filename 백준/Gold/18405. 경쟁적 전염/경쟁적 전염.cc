#include <bits/stdc++.h>

using namespace std;

int N, K;
int S, Y, X;
vector<vector<int>> board;
vector<queue<pair<int, int>>> q;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void BFS()
{
	for (int k = 1; k <= K; k++)
	{
		int size = q[k].size();

		for (int s = 0; s < size; s++)
		{
			auto [y, x] = q[k].front();
			q[k].pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY < 1 || newY > N || newX < 1 || newX > N)continue;
				if (board[newY][newX] != 0) continue;

				board[newY][newX] = k;
				q[k].push({ newY,newX });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> K;

	board.resize(N+1, vector<int>(N+1));
	q.resize(K + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				q[board[i][j]].push({ i, j });
			}
		}
	}

	cin >> S >> Y >> X;
	
	while (S--)
	{
		BFS();
	}

	cout << board[Y][X];
	
	return 0;
}