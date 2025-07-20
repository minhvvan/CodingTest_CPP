#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M, D;
vector<vector<int>> grid;
vector<pair<int, int>> enemies;
int ans = 0;

int Simulate(vector<int>& archers)
{
	int moves = 0;
	int killCnt = 0;
	int enemiesCnt = enemies.size();
	vector<bool> movable(enemiesCnt, true);
	while (enemiesCnt > 0)
	{
		set<int> target;

		for (int i = 0 ; i < archers.size(); i++)
		{
			int minDist = MAX;
			int minEnemy = -1;

			for (int j = 0; j < enemies.size(); j++)
			{
				if (!movable[j]) continue;
				auto [y, x] = enemies[j];
				y += moves;
				if (y >= N)
				{
					movable[j] = false;
					enemiesCnt--;
					continue;
				}

				int dist = abs(y - N) + abs(x - archers[i]);
				if (dist > D) continue;

				if (dist < minDist)
				{
					minDist = dist;
					minEnemy = j;
				}
			}

			if (minEnemy != -1)
			{
				target.insert(minEnemy);
			}
		}

		for (auto enemy : target)
		{
			movable[enemy] = false;
			enemiesCnt--;
			killCnt++;
		}

		moves++;
	}

	return killCnt;
}

void DFS(vector<int>& archers, int idx)
{
	if (archers.size() == 3)
	{
		ans = max(ans, Simulate(archers));
		return;
	}

	for (int i = idx; i < M; i++)
	{
		archers.push_back(i);
		DFS(archers, i + 1);
		archers.pop_back();
	}
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M >> D;
	
	grid.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j])
			{
				enemies.push_back({ i,j });
			}
		}
	}

	sort(enemies.begin(), enemies.end(), cmp);

	vector<int> temp;
	DFS(temp, 0);

	cout << ans;
}