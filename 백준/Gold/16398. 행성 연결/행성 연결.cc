#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<vector<int>> board;
vector<long long> visited;
long long ans;

void Connect()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });

	while (!pq.empty())
	{
		auto [cost, current] = pq.top();
		pq.pop();

		cost *= -1;

		if (visited[current] != LLONG_MAX) continue;
		visited[current] = cost;

		for (int i = 0; i < N; i++)
		{
			if (i == current) continue;

			if (visited[i] > cost + board[current][i])
			{
				pq.push({ -board[current][i], i });
			}
		}
	}

	for (auto cost : visited)
	{
		ans += cost;
	}
}

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N;

	board.resize(N, vector<int>(N));
	visited.resize(N, LLONG_MAX);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	//0번 노드를 시작으로 모두 연결시키기 
	Connect();

	cout << ans;

	return 0;
}