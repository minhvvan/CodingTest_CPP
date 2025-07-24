#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M, K;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> M >> K;
	grid.resize(N, vector<char>(M, '.'));
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;

		grid[a-1][b-1] = '#';
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]) continue;
			if (grid[i][j] != '#') continue;

			visited[i][j] = true;

			queue<pair<int, int>> q;
			q.push({ i,j });

			int cnt = 1;
			while (!q.empty())
			{
				auto [y, x] = q.front();
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int newY = y + dy[k];
					int newX = x + dx[k];

					if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
					if (visited[newY][newX]) continue;
					if (grid[newY][newX] != '#') continue;

					cnt++;
					q.push({ newY, newX });
					visited[newY][newX] = true;
				}
			}

			ans = max(ans, cnt);
		}
	}

	cout << ans;

}