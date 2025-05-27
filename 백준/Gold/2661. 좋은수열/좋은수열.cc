#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<vector<string>> dp;

bool Check(string& prev)
{
	int size = prev.length();

	for (int i = 1; i <= prev.length() / 2; i++)
	{
		auto left = prev.substr(size - i * 2, i);
		auto right = prev.substr(size - i, i);

		if (left == right) return false;
	}

	return true;
}

bool IsLess(string& origin, string& target)
{
	if (origin.length() == 0) return true;

	for(int i = 0 ; i < origin.length(); i++)
	{
		if (origin[i] - '0' == target[i] - '0') continue;
		return origin[i] - '0' > target[i] - '0';
	}
}

int main() 
{
    INPUT_OPTIMIZE;

	cin >> N;
	dp.resize(N + 1, vector<string>(4));

	dp[1][1] = "1";
	dp[1][2] = "2";
	dp[1][3] = "3";

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				if (j == k) continue;
				if (dp[i - 1][k] == "") continue;

				auto prev = dp[i - 1][k];
				prev += to_string(j);

				if (Check(prev) && (dp[i][j] == "" || IsLess(dp[i][j], prev)))
				{
					dp[i][j] = prev;
				}
			}
		}
	}


	string ans = dp[N][1];
	if (dp[N][2] != "" && IsLess(ans, dp[N][2]))
	{
		ans = dp[N][2];
	}

	if (dp[N][3] != "" && IsLess(ans, dp[N][3]))
	{
		ans = dp[N][3];
	}

	cout << ans;

	return 0;
} 