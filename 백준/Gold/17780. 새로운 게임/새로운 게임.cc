#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

enum DIR
{
	RIGHT,
	UP,
	LEFT,
	DOWN
};

enum BLANKCOLOR
{
	WHITE,
	RED,
	BLUE
};

vector<int> dy = { 0, -1, 0, 1 };
vector<int> dx = { 1, 0, -1, 0 };

bool CheckEnd(vector<vector<vector<int>>>& Board)
{
	for (auto row : Board)
	{
		for (auto cell : row)
		{
			if (cell.size() >= 4) return true;
		}
	}

	return false;
}

void Move(vector<vector<vector<int>>>& Board, vector<vector<int>>& Color, vector<tuple<int, int, int>>& Pawn, int y, int x, int& dir)
{
	int newY = y + dy[dir];
	int newX = x + dx[dir];

	if (newY < 0 || newY >= Board.size() || newX < 0 || newX >= Board.size())
	{
		//반대로
		dir = (dir + 2) % 4;
		newY = y + dy[dir];
		newX = x + dx[dir];

		if (Color[newY][newX] == BLUE) return;

		Move(Board, Color, Pawn, y, x, dir);
		return;
	}

	switch (Color[newY][newX])
	{
	case WHITE:
		for (auto pawn : Board[y][x])
		{
			Board[newY][newX].push_back(pawn);

			get<0>(Pawn[pawn]) = newY;
			get<1>(Pawn[pawn]) = newX;
		}

		while (!Board[y][x].empty()) Board[y][x].pop_back();
		break;
	case RED:
		while (!Board[y][x].empty())
		{
			auto temp = Board[y][x].back();
			Board[newY][newX].push_back(temp);
			Board[y][x].pop_back();

			get<0>(Pawn[temp]) = newY;
			get<1>(Pawn[temp]) = newX;
		}
		break;
	case BLUE:
		dir = (dir + 2) % 4;
		newY = y + dy[dir];
		newX = x + dx[dir];

		if ((newY < 0 || newY >= Board.size() || newX < 0 || newX >= Board.size())) break;
		if (Color[newY][newX] == BLUE) break;

		Move(Board, Color, Pawn, y, x, dir);
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> Color(N, vector<int>(N, 0));
	vector<vector<vector<int>>> Board(N, vector<vector<int>>(N));
	vector<tuple<int,int,int>> Pawn(K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Color[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int r, c, d, dir;
		cin >> r >> c >> d;

		if (d == 1) dir = RIGHT;
		else if (d == 2) dir = LEFT;
		else if (d == 3) dir = UP;
		else dir = DOWN;

		Pawn[i] = { r - 1, c - 1, dir };
		Board[r-1][c-1].push_back(i);
	}

	int cnt = 0;
	while (!CheckEnd(Board) && cnt <= 1000)
	{
		for (int i = 0; i < K; i++)
		{
			int y = get<0>(Pawn[i]);
			int x = get<1>(Pawn[i]);
			int& d = get<2>(Pawn[i]);

			//제일 아래X => 못움직임
			if (Board[y][x][0] != i) continue;

			Move(Board, Color, Pawn, y, x, d);
		}

		cnt++;
	}

	if (cnt <= 1000) cout << cnt;
	else cout << -1;

	return 0;
}