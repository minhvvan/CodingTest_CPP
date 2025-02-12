#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> board;
vector<int> dy = { 0, 0, 1, 1 };
vector<int> dx = { 0, 1, 0, 1 };

string Compress(int size, int y, int x)
{
	if (size == 1)
	{
		string result;
		result += board[y][x];
		return result;
	}

	char target = board[y][x];
	string result = "(";

	bool bSame = true;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (target != board[i][j])
			{
				bSame = false;
				break;
			}
		}
	}

	if (bSame)
	{
		result = target;
	}
	else
	{
		int quard = size / 2;

		for (int i = 0; i < 4; i++)
		{
			result += Compress(quard, y + dy[i] * quard, x + dx[i] * quard);
		}

		result += ")";
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	board.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	cout << Compress(N, 0, 0);
	
	return 0;
}