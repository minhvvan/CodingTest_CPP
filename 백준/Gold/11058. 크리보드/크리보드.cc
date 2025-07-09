#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<long long> dp;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	dp.resize(N + 1, 0);

	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 3; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}

	cout << dp[N];

	return 0;
}