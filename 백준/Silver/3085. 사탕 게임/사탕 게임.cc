#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<string> board;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int CheckCoutinus(int i, int j)
{
	char origin = board[i][j];

	//가로
	pair<int, int> left = { i,j };
	pair<int, int> right = { i,j };
	int h = 1;
	bool bCanLeft = true;
	bool bCanRight = true;
	while(left.second > 0 || right.second < N)
	{
		if (left.second > 0 && bCanLeft)
		{
			left.second--;
			if (board[left.first][left.second] == origin)
			{
				h++;
			}
			else
			{
				bCanLeft = false;
			}
		}

		if (right.second < N - 1 && bCanRight)
		{
			right.second++;
			if (board[right.first][right.second] == origin)
			{
				h++;
			}
			else
			{
				bCanRight = false;
			}
		}

		if ((left.second <= 0 || !bCanLeft) && (right.second >= N-1 || !bCanRight)) break;
	}

	//세로
	pair<int, int> up = { i,j };
	pair<int, int> down = { i,j };
	int v = 1;
	bool bCanUp = true;
	bool bCanDown = true;
	while (up.first > 0 || down.first < N)
	{
		if (up.first > 0 && bCanUp)
		{
			up.first--;
			if (board[up.first][up.second] == origin)
			{
				v++;
			}
			else
			{
				bCanUp = false;
			}
		}

		if (down.first < N - 1 && bCanDown)
		{
			down.first++;
			if (board[down.first][down.second] == origin)
			{
				v++;
			}
			else
			{
				bCanDown = false;
			}
		}

		if ((up.first <= 0 || !bCanUp) && (down.first >= N-1 || !bCanDown)) break;
	}

	return max(h, v);
}

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//swap을 안하고
			ans = max(ans, CheckCoutinus(i, j));

			for (int k = 0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];

				if (y < 0 || y >= N || x < 0 || x >= N) continue;
				if (board[i][j] == board[y][x]) continue;

				swap(board[i][j], board[y][x]);
				ans = max(ans, CheckCoutinus(i, j));
				swap(board[i][j], board[y][x]);
			}
		}
	}

	cout << ans;

	return 0;
}