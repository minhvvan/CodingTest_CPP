#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> v;
vector<int> dp;

const int MAX = 987654321;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	v.resize(N);
	dp.resize(N, MAX);
	
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	/*
	* 0번부터 N-1번까지 가야함
	* 
	* dp[i + v[i]] = min(dp[i+v[i]], dp[i] + 1)
	* 
	*/

	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int jump = v[i];

		for (int j = 1; j <= jump; j++)
		{
			if (i + j >= N) break;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}


	if (dp[N - 1] == MAX) cout << -1;
	else cout << dp[N - 1];

	return 0;
}