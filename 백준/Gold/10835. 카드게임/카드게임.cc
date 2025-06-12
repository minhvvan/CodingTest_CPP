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

int DFS(int l, int r)
{
	// 가지치기
	if (l == N || r == N) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	dp[l][r] = max(DFS(l + 1, r), DFS(l + 1, r + 1));

	//오른쪽 버리기
	if (leftCards[l] > rightCards[r])
	{
		dp[l][r] = max(dp[l][r], DFS(l, r + 1) + rightCards[r]);
	}

	return dp[l][r];
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

	cout << DFS(0, 0);

	return 0;
}