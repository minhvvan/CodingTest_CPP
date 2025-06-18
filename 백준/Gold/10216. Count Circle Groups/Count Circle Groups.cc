#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, N;
vector<tuple<int, int, int>> towers;
vector<bool> visited;

int main()
{
	INPUT_OPTIMIZE;

	cin >> T;

	while (T--)
	{
		cin >> N;

		towers.clear();
		visited.clear();
		visited.resize(N, false);

		for (int i = 0; i < N; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			towers.push_back({ x,y,d });
		}

		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			if (visited[i]) continue;
			ans++;

			queue<int> q;
			q.push(i);

			while (!q.empty())
			{
				int idx = q.front();
				q.pop();

				if (visited[idx]) continue;
				visited[idx] = true;

				auto& [y1, x1, d1] = towers[idx];
				for (int j = 0; j < N; j++)
				{
					if (visited[j]) continue;

					auto& [y2, x2, d2] = towers[j];
					float dist = sqrt(abs(y2 - y1) * abs(y2 - y1) + abs(x2 - x1) * abs(x2 - x1));

					if (dist <= d1 + d2)
					{
						q.push(j);
					}
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}