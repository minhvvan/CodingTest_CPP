#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long
#define INF 2e9

using namespace std;
int N, T;
vector<pair<int,int>> chapters;
vector<vector<int>> dp;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N >> T;
	dp.resize(N + 1, vector<int>(T + 1, 0));

	chapters.push_back({ 0, 0 });

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		chapters.push_back({ a,b });
	}

	sort(chapters.begin(), chapters.end());

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= T; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (j - chapters[i].first < 0) continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - chapters[i].first] + chapters[i].second);
		}
	}

	cout << dp[N][T];

	return 0;
}