#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int ans = INT_MAX;

vector<int> dy = { 0, 1, 0, -1, 0 };
vector<int> dx = { 0, 0, 1, 0, -1 };

void DFS(int depth, int cost)
{
	if (depth == 3)
	{
		ans = min(ans, cost);
		return;
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			bool bPossible = true;

			vector<pair<int, int>> v;

			for (int k = 0; k < 5; k++)
			{
				int newY = i + dy[k];
				int newX = j + dx[k];

				if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
				if (visited[newY][newX])
				{
					bPossible = false;
					break;
				}

				v.push_back({ newY, newX });
			}

			if (bPossible)
			{
				int temp = 0;

				for(auto& [y, x] : v)
				{
					temp += grid[y][x];
					visited[y][x] = true;
				}

				DFS(depth + 1, cost + temp);

				for (auto& [y, x] : v)
				{
					visited[y][x] = false;
				}
			}
		}
	}
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;
	grid.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	DFS(0, 0);

	cout << ans;

	return 0;
}