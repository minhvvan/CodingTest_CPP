#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<tuple<int, int, int>> opers;
vector<vector<int>> board;

vector<int> dy = { 1, 0, -1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void Print(vector<vector<int>>& arr)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "\n";
	}

	cout << "\n";
}

void Rotate(vector<vector<int>>& arr, int y, int x, int size)
{
	for (int s = size; s > 0; s--)
	{
		int moveSize = s * 2 + 1;

		int posY = y - s;
		int posX = x - s;

		int temp = arr[posY][posX];

		for (int t = 0; t < 4; t++)
		{
			for (int k = 1; k < moveSize; k++)
			{
				int nextY = posY + dy[t];
				int nextX = posX + dx[t];
				
				arr[posY][posX] = arr[nextY][nextX];

				posY = nextY;
				posX = nextX;
			}
		}

		arr[posY - dy[3]][posX - dx[3]] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M >> K;
	
	board.resize(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;

		opers.push_back({ r, c, s });
	}

	sort(opers.begin(), opers.end());

	int ans = INT_MAX;
	do 
	{
		auto temp(board);
		for (auto [r, c, s] : opers)
		{
			Rotate(temp, r, c, s);
		}

		for (int i = 1; i <= N; i++)
		{
			int sum = 0;
			for (int j = 1; j <= M; j++)
			{
				sum += temp[i][j];
			}

			ans = min(ans, sum);
		}

	} while (next_permutation(opers.begin(), opers.end()));

	cout << ans;

	return 0;
}