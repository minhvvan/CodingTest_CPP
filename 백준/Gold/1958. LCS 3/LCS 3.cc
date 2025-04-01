#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
vector<string> strs(3);
int dp[101][101][101] = { 0, };
int len0, len1, len2;

int main() 
{
	INPUT_OPTIMIZE;

	for (int i = 0; i < 3; i++)
	{
		cin >> strs[i];
		strs[i] = ' ' + strs[i];
	}

	len0 = strs[0].length();
	len1 = strs[1].length();
	len2 = strs[2].length();

	for (int i = 1; i < len0; i++)
	{
		for (int j = 1; j < len1; j++)
		{
			for (int k = 1; k < len2; k++)
			{
				if (strs[0][i] == strs[1][j] && strs[1][j] == strs[2][k])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; 
				}
				else
				{
					int result = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					result = max(result, dp[i][j][k - 1]);

					dp[i][j][k] = result;
				}
			}
		}
	}

	cout << dp[len0 - 1][len1 - 1][len2 - 1];

	return 0;
}