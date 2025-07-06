#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 20 * 5000 + 1

using namespace std;
int N, K;
vector<pair<int, int>> powers;
vector<int> dp;
int ans = MAX;

void DFS(int idx, bool useBigJump, int cost)
{
	if (idx == N-1)
	{
		ans = min(ans, cost);
		return;
	}

	if (cost > ans) return;

	if (idx + 1 < N)
	{
		DFS(idx + 1, useBigJump, cost + powers[idx].first);
	}

	if (idx + 2 < N)
	{
		DFS(idx + 2, useBigJump, cost + powers[idx].second);
	}

	if (!useBigJump && idx + 3 < N)
	{
		DFS(idx + 3, true, cost + K);
	}
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		powers.push_back({ a,b });
	}

	cin >> K;

	DFS(0, false, 0);
	cout << ans;

	return 0;
}