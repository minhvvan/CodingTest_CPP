#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> leftCards;
vector<int> rightCards;
vector<vector<int>> dp;
int ans = 0;

void DFS(int l, int r, int score)
{
	if (l == N || r == N)
	{
		ans = max(ans, score);
		return;
	}

	// 가지치기
	if (dp[l][r] >= score) return;
	dp[l][r] = score;

	//오른쪽 버리기
	if (leftCards[l] > rightCards[r])
	{
		DFS(l, r + 1, score + rightCards[r]);
	}

	//왼쪽만 버리기
	DFS(l + 1, r, score);

	//둘다 버리기
	DFS(l + 1, r + 1, score);
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	leftCards.resize(N);
	rightCards.resize(N);

	dp.resize(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++)
	{
		cin >> leftCards[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> rightCards[i];
	}

	DFS(0, 0, 0);

	cout << ans;

	return 0;
}