#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
map<int, long long> m;
vector<int> sum;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> K;
	sum.resize(N + 1, 0);

	long long ans = 0;
	m[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;

		sum[i] = sum[i - 1] + x;

		ans += m[sum[i] - K];
		m[sum[i]]++;
	}

	cout << ans;

	return 0;
}