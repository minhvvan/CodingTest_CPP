#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> costs;
vector<int> rewards;
vector<int> dp;
const int MAX = 20 * 100 + 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N;

	costs.resize(N + 1);
	rewards.resize(N + 1);
	dp.resize(101, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> costs[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> rewards[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 100; j >= costs[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - costs[i]] + rewards[i]);
		}
	}

	cout << dp[99];

	return 0;
}