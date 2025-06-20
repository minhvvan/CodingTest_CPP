#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

enum Operate
{
	None,
	DIV3,
	DIV2,
	MINUS,
};

vector<pair<int,int>> dp;
const int MAX = 987654321;


int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	dp.resize(N + 1, { MAX , None });

	dp[N] = { 0, None };
	for (int i = N; i > 0; i--)
	{
		if (i % 3 == 0)
		{
			if (dp[i / 3].first > dp[i].first + 1)
			{
				dp[i / 3] = { dp[i].first + 1, DIV3 };
			}
		}

		if (i % 2 == 0)
		{
			if (dp[i / 2].first > dp[i].first + 1)
			{
				dp[i / 2] = { dp[i].first + 1, DIV2 };
			}
		}

		if (dp[i - 1].first > dp[i].first + 1)
		{
			dp[i - 1] = { dp[i].first + 1, MINUS };
		}
	}

	cout << dp[1].first << "\n";
	int temp = 1;
	vector<int> result;
	while (temp != N)
	{
		result.push_back(temp);
		if (dp[temp].second == DIV3) temp *= 3;
		else if (dp[temp].second == DIV2) temp *= 2;
		else if (dp[temp].second == MINUS) temp++;
	}

	cout << N << " ";

	while (!result.empty())
	{
		cout << result.back() << " ";
		result.pop_back();
	}

	return 0;
}