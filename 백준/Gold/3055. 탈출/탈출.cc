#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<string> grid;
pair<int, int> start, target;
vector<vector<bool>> visited;
queue<pair<int, int>> water;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void SpreadWater()
{
	int size = water.size();

	for (int k = 0; k < size; k++)
	{
		auto [y, x] = water.front();
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];

			if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
			if (grid[newY][newX] != '.') continue;

			grid[newY][newX] = '*';
			water.push({ newY, newX });
		}
	}
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;
	
	grid.resize(N);
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> grid[i];

		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 'D')
			{
				target = { i,j };
			}
			else if (grid[i][j] == 'S')
			{
				start = { i, j };
			}
			else if (grid[i][j] == '*')
			{
				water.push({ i,j });
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;

	int depth = 1;

	while(!q.empty())
	{ 
		int size = q.size();

		// 물
		SpreadWater();

		for (int k = 0; k < size; k++)
		{
			auto [y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
				if (grid[newY][newX] == 'D')
				{
					cout << depth;
					return 0;
				}
				if (visited[newY][newX]) continue;
				if (grid[newY][newX] != '.') continue;

				visited[newY][newX] = true;
				q.push({ newY, newX });
			}
		}

		depth++;
	}

	cout << "KAKTUS";

	return 0;
}