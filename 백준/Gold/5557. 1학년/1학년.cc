#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
vector<vector<long long>> dp;
int ans = 0;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	dp.resize(N, vector<long long>(21, 0));

	dp[0][nums[0]] = 1;
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - nums[i] >= 0)
			{
				dp[i][j - nums[i]] += dp[i - 1][j];
			}

			if (j + nums[i] <= 20)
			{
				dp[i][j + nums[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N-2][nums.back()];

	return 0;
}