#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;
vector<vector<int>> dp;
vector<int> prefixSum;
const int MIN = -987654321;

int Solve(int n, int m)
{
	if (n < m * 2 - 1) return MIN;
	if (m == 0) return 0;
	if (dp[n][m] != MIN) return dp[n][m];

	dp[n][m] = Solve(n - 1, m);

	for (int i = n; i >= 1; i--) 
	{
		int temp = Solve(i - 2, m - 1);
		dp[n][m] = max(dp[n][m], temp + prefixSum[n] - prefixSum[i - 1]);
	}

	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;
	
	nums.resize(N+1);
	prefixSum.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		if (i == 0) prefixSum[i] = nums[i];
		else prefixSum[i] = prefixSum[i - 1] + nums[i];
	}
	
	dp.resize(N+1, vector<int>(M+1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = MIN;
		}
	}

	cout << Solve(N, M);

	return 0;
}