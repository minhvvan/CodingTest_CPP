#include <bits/stdc++.h>

using namespace std;

int N, S, M;
vector<int> V;
vector<vector<bool>> dp;
const int INVALID = -50 * 10000;

int dfs(int idx, int volume)
{
	if (idx == N)
	{
		return volume;
	}

	if (dp[idx][volume]) return INVALID;
	dp[idx][volume] = true;

	int plus = INVALID;
	if (volume + V[idx] <= M)
	{
		plus = dfs(idx + 1, volume + V[idx]);
	}

	int minus = INVALID;
	if (volume - V[idx] >= 0)
	{
		minus = dfs(idx + 1, volume - V[idx]);
	}

	return max(plus, minus);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> S >> M;

	V.resize(N);
	dp.resize(N, vector<bool>(M+1, false));
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
	}

	/*
	* N <= 50
	* S에서 V[i]를 +, -를 살펴보며 가능한 경우 살펴보기 -> 둘다 불가능 return
	* 마지막곡에 가면 갱신
	* dfs
	*/

	int ans = dfs(0, S);
	if (ans == INVALID)
	{
		ans = -1;
	}

	cout << ans;

	return 0;
}