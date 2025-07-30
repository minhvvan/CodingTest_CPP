#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int T;

int main()
{
	INPUT_OPTIMIZE;

	cin >> T;

	while (T--)
	{
		int N, target;
		cin >> N;

		vector<int> coins;
		vector<int> dp;
		coins.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> coins[i];
		}

		cin >> target;
		dp.resize(target + 1, 0);
		dp[0] = 1;

		for (auto& coin : coins)
		{
			for (int i = coin; i <= target; i++)
			{
				dp[i] += dp[i - coin];
			}
		}

		cout << dp[target] << "\n";
	}
}