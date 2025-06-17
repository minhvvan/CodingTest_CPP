#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, V, E;
vector<vector<int>> adj;
vector<int> visited;

int main()
{
	INPUT_OPTIMIZE;

	cin >> T;

	while (T--)
	{
		cin >> V >> E;

		adj.clear();
		adj.resize(V + 1, vector<int>());

		visited.clear();
		visited.resize(V + 1, 0);

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		/*
		* 임의 노드를 시작으로 dfs혹은 bfs
		* 12로 플래그 전달 0이면 기록
		* 0이 아니면 일치하는지 확인
		* 0이 아닌 지점이 있는데 플래그가 다르면 이분 그래프 아님
		*/

		queue<pair<int,int>> q;
		bool bPossible = true;

		for (int i = 1; i <= V; i++)
		{
			if (!bPossible) break;
			if (visited[i] != 0) continue;

			q.push({ i, 1 });

			while (!q.empty())
			{
				auto [current, flag] = q.front();
				q.pop();

				if (visited[current] == flag) continue;
				visited[current] = flag;

				auto nextFlag = flag == 1 ? 2 : 1;
				for (auto next : adj[current])
				{
					if (visited[next] == 0)
					{
						q.push({ next, nextFlag });
						continue;
					}

					if (visited[next] != nextFlag)
					{
						cout << "NO\n";
						bPossible = false;
						break;
					}
				}

				if (!bPossible) break;
			}
		}

		if (bPossible) cout << "YES\n";
	}
	

	return 0;
}