#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> str1 >> str2;

	vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));

	int ans = 0;

	for (int i = 0; i < str1.size(); i++)
	{
		dp[i][0] = str1[i] == str2[0] ? 1 : 0;
	}

	for (int i = 0; i < str2.size(); i++)
	{
		dp[0][i] = str1[0] == str2[i] ? 1 : 0;
	}

	for (int i = 1; i < str1.size(); i++)
	{
		for (int j = 1; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;

	return 0;
}