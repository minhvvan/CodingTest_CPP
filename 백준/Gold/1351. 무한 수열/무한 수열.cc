#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long N, P, Q;
map<long long, long long> dp;

long long DFS(long long n)
{
	if (dp.find(n) != dp.end())
	{
		return dp[n];
	}

	return dp[n] = DFS(n / P) + DFS(n / Q);
}

int main()
{
    INPUT_OPTIMIZE;

	cin >> N >> P >> Q;
	dp[0] = 1;

	long long ans = DFS(N);
	cout << ans;

	return 0;
} 