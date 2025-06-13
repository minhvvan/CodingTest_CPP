#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, W;
vector<int> plums;
int dp[31][2][1001];

int main()
{
	INPUT_OPTIMIZE;

	cin >> T >> W;
	plums.resize(T + 1);
	
	for (int i = 1; i <= T; i++)
	{
		cin >> plums[i];
	}

	for (int j = 0; j <= W; j++)
	{
		for (int i = 1; i <= T; i++)
		{
			if (j == 0)
			{	
				dp[j][0][i] = dp[j][0][i - 1] + (plums[i] == 1);
			}
			else
			{
				dp[j][0][i] = max(dp[j][0][i - 1] + (plums[i] == 1), dp[j - 1][1][i - 1] + (plums[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (plums[i] == 2), dp[j - 1][0][i - 1] + (plums[i] == 2));
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			ans = max(ans, dp[j][i][T]);
		}
	}

	cout << ans << '\n';


	return 0;
}