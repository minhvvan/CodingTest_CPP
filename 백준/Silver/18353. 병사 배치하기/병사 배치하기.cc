#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
vector<int> nums;
vector<int> dp;
vector<int> L;
int N;

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	nums.resize(N);
	dp.resize(N);
	L.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	reverse(nums.begin(), nums.end());

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		auto pos = lower_bound(L.begin(), L.begin() + cnt, nums[i]) - L.begin();
		dp[i] = pos;

		L[dp[i]] = nums[i];
		if (dp[i] + 1> cnt) cnt++;
	}

	cout << N - cnt;

	return 0;
}