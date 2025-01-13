#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<long long>> dp(31, vector<long long>(31, 0));
long long ans = 0;

long long dfs(int w, int h) 
{
	if (h == -1)return 0;
	if (w == 0)return 1;

	long long& ret = dp[w][h];
	if (ret) return dp[w][h];

	ret = dfs(w - 1, h + 1) + dfs(w, h - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	while (cin >> N)
	{
		if (N == 0) break;

		cout << dfs(N, 0) << endl;
	}

	return 0;
}