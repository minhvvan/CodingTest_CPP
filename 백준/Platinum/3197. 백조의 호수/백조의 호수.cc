#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

bool Check(vector<vector<char>>& lake, queue<pair<int,int>>& canMove, vector<vector<bool>>& visited)
{
	vector<int> dy = { -1, 0, 1, 0 };
	vector<int> dx = { 0, 1, 0, -1 };

	queue<pair<int, int>> nextCanMove;

	while (!canMove.empty())
	{
		auto [y, x] = canMove.front();
		canMove.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= lake.size() || newX < 0 || newX >= lake[0].size()) continue;
			if (visited[newY][newX]) continue;

			visited[newY][newX] = true;

			if (lake[newY][newX] == 'X')
			{
				nextCanMove.push({ newY, newX });
				continue;
			}
			if (lake[newY][newX] == 'L') return true;
			
			canMove.push({ newY, newX });
		}
	}

	canMove = move(nextCanMove);

	return false;
}

void Melt(vector<vector<char>>& lake, queue<pair<int, int>>& water)
{
	vector<int> dy = { -1, 0, 1, 0 };
	vector<int> dx = { 0, 1, 0, -1 };

	int waterCnt = water.size();

	while (waterCnt--)
	{
		auto [y, x] = water.front();
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= lake.size() || newX < 0 || newX >= lake[0].size()) continue;

			if (lake[newY][newX] == 'X')
			{
				lake[newY][newX] = '.';
				water.push({ newY, newX });
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C;
	cin >> R >> C;

	vector<vector<char>> lake(R, vector<char>(C, 0));
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	queue<pair<int, int>> canMove;
	queue<pair<int, int>> water;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> lake[i][j];
			if (lake[i][j] == '.' || lake[i][j] == 'L') water.push({i, j});
			if (lake[i][j] == 'L' && canMove.empty()) canMove.push({ i, j });
		}
	}

	auto [swanY, swanX] = canMove.front();
	visited[swanY][swanX] = true;

	int answer = 0;

	while (!Check(lake, canMove, visited))
	{
		Melt(lake, water);
		answer++;
	}

	cout << answer;

	return 0;
}