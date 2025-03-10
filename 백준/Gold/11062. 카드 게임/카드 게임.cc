#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> cards;
int dp[1001][1001];

int TakeCard(int left, int right, bool bMax)
{
	if (left > right) return 0;
	if (dp[left][right] != 0) return dp[left][right];

	if (bMax)
	{
		return dp[left][right] = max(cards[left] + TakeCard(left + 1, right, false), cards[right] + TakeCard(left, right - 1, false));
	}
	else
	{
		return dp[left][right] = min(TakeCard(left + 1, right, true), TakeCard(left, right - 1, true));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;
		cards.resize(N);
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < N; i++)
		{
			cin >> cards[i];
		}

		cout << TakeCard(0, N-1, true) << "\n";
	}

	return 0;
}