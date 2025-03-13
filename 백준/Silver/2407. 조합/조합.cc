#include <bits/stdc++.h>
using namespace std;

int N, M;
string dp[101][101];

string Add(string a, string b)
{
	string res = "";
	int len1 = a.length();
	int len2 = b.length();
	int len = len1 > len2 ? len1 : len2;
	int sum = 0;

	for (int i = 0; i < len || sum; i++) {
		if (len1 > i) sum += a[i] - '0';
		if (len2 > i) sum += b[i] - '0';

		res += (sum % 10) + '0';
		sum /= 10;
	}

	return res;
}

string Comb(int n, int m)
{
	if (m == 0 || n == m) return dp[n][m] = "1";

	if (dp[n][m] != "") return dp[n][m];

	return dp[n][m] = Add(Comb(n - 1, m - 1), Comb(n - 1, m));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	Comb(N, M);

	for (int i = dp[N][M].length() - 1; i >= 0; i--)
		cout << dp[N][M][i];

	return 0;
}