#include <bits/stdc++.h>

using namespace std;

int T;
const int MOD = 1'000'000'009;
vector<vector<int>> dp(100'001, vector<int>(4, 0));

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;

	for (int i = 3; i <= 100'000; i++)
	{
		if (i - 1 > 0)
		{
			dp[i][1] = (dp[i][1] + dp[i - 1][2]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i - 1][3]) % MOD;
		}
		if (i - 2 > 0)
		{
			dp[i][2] = (dp[i][2] + dp[i - 2][1]) % MOD;
			dp[i][2] = (dp[i][2] + dp[i - 2][3]) % MOD;
		}
		if (i - 3 > 0)
		{
			dp[i][3] = (dp[i][3] + dp[i - 3][1]) % MOD;
			dp[i][3] = (dp[i][3] + dp[i - 3][2]) % MOD;
		}
	}

	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		auto temp = (dp[n][1] + dp[n][2]) % MOD;
		cout << (temp + dp[n][3]) % MOD << "\n";
	}

	return 0;
}