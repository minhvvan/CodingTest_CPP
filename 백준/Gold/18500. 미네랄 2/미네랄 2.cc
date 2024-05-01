#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

vector<int> dy = { 0, -1, 0, 1 };
vector<int> dx = { 1, 0, -1, 0 };

enum
{
	LEFT,
	RIGHT
};

void MoveDown(vector<vector<char>>& Mineral, vector<vector<bool>>& visited)
{
	int minDiff = Mineral.size() - 1;

	for (int j = 0; j < Mineral[0].size(); j++)
	{
		int ground = Mineral.size();

		for (int i = Mineral.size()-1; i >= 0; i--)
		{
			if (Mineral[i][j] == 'x' && !visited[i][j]) ground = i;
			if (Mineral[i][j] == 'x' && visited[i][j])
			{
				minDiff = min(minDiff, ground - i - 1);
			}
		}
	}

	for (int i = Mineral.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < Mineral[0].size(); j++)
		{
			if (visited[i][j])
			{
				Mineral[i + minDiff][j] = 'x';
				Mineral[i][j] = '.';
			}
		}
	}
}

void CheckInAir(vector<vector<char>>& Mineral, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		vector<vector<bool>> visited(Mineral.size(), vector<bool>(Mineral[0].size(), false));
		queue<pair<int, int>> q;

		int startY = i + dy[k];
		int startX = j + dx[k];

		if (startY < 0 || startY >= Mineral.size() || startX < 0 || startX >= Mineral[0].size()) continue;
		if (Mineral[startY][startX] == '.') continue;
		q.push({ startY, startX });
		visited[startY][startX] = true;

		bool bTouchGround = false;
		while (!q.empty())
		{
			auto [y, x] = q.front();
			q.pop();

			if (y == Mineral.size()-1)
			{
				bTouchGround = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY < 0 || newY >= Mineral.size() || newX < 0 || newX >= Mineral[0].size()) continue;
				if (visited[newY][newX] || Mineral[newY][newX] == '.') continue;

				visited[newY][newX] = true;
				q.push({ newY,newX });
			}
		}

		if (bTouchGround) continue;
		else MoveDown(Mineral, visited);
	}
}

void Throw(vector<vector<char>>& Mineral, int height, int dir)
{
	int x = -1;

	if (dir == LEFT)
	{
		for (int j = 0; j < Mineral[height].size(); j++)
		{
			if (Mineral[height][j] == 'x')
			{
				x = j;
				break;
			}
		}
	}
	else
	{
		for (int j = Mineral[height].size()-1; j >= 0; j--)
		{
			if (Mineral[height][j] == 'x')
			{
				x = j;
				break;
			}
		}
	}

	if (x != -1)
	{
		Mineral[height][x] = '.';
		CheckInAir(Mineral, height, x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C, N;
	cin >> R >> C;

	vector<vector<char>> Mineral(R, vector<char>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Mineral[i][j];
		}
	}

	cin >> N;
	vector<int> Stick(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		Stick[i] = R - temp;
	}

	for (int i = 0; i < N; i++)
	{
		Throw(Mineral, Stick[i], i % 2);
	}

	for (int i = 0; i < Mineral.size(); i++)
	{
		for (int j = 0; j < Mineral[0].size(); j++)
		{
			cout << Mineral[i][j];
		}
		cout << "\n";
	}

	return 0;
}