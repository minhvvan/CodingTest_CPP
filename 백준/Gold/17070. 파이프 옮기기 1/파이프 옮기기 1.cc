#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<vector<int>> board;
int ans = 0;

enum
{
	Horizontal,
	Vertical,
	Diagnal
};

void DFS(pair<int,int> a, pair<int,int> b, int type)
{
	if (b.first == N - 1 && b.second == N - 1)
	{
		ans++;
		return;
	}

	if (type == Horizontal)
	{
		//가로
		if (b.second < N - 1 && board[b.first][b.second + 1] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.second++;
			newPosB.second++;

			DFS(newPosA, newPosB, Horizontal);
		}

		//대각
		if (b.second < N - 1 && b.first < N - 1 
			&& board[b.first][b.second + 1] == 0 && board[b.first + 1][b.second] == 0 && board[b.first + 1][b.second + 1] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.second++;
			newPosB.first++;
			newPosB.second++;

			DFS(newPosA, newPosB, Diagnal);
		}
	}
	else if (type == Vertical)
	{
		//세로
		if (b.first < N - 1 && board[b.first + 1][b.second] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.first++;
			newPosB.first++;

			DFS(newPosA, newPosB, Vertical);
		}

		//대각
		if (b.second < N - 1 && b.first < N - 1
			&& board[b.first][b.second + 1] == 0 && board[b.first + 1][b.second] == 0 && board[b.first + 1][b.second + 1] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.first++;
			newPosB.first++;
			newPosB.second++;

			DFS(newPosA, newPosB, Diagnal);
		}
	}
	else
	{
		//가로
		if (b.second < N - 1 && board[b.first][b.second + 1] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.first++;
			newPosA.second++;
			newPosB.second++;

			DFS(newPosA, newPosB, Horizontal);
		}

		//세로
		if (b.first < N - 1 && board[b.first + 1][b.second] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.first++;
			newPosA.second++;
			newPosB.first++;

			DFS(newPosA, newPosB, Vertical);
		}

		//대각
		if (b.second < N - 1 && b.first < N - 1
			&& board[b.first][b.second + 1] == 0 && board[b.first + 1][b.second] == 0 && board[b.first + 1][b.second + 1] == 0)
		{
			auto newPosA = a;
			auto newPosB = b;
			newPosA.first++;
			newPosA.second++;
			newPosB.first++;
			newPosB.second++;

			DFS(newPosA, newPosB, Diagnal);
		}
	}
}

int main() 
{
    INPUT_OPTIMIZE;

	cin >> N;

	board.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	DFS({ 0,0 }, { 0,1 }, Horizontal);

	cout << ans;

	return 0;
} 