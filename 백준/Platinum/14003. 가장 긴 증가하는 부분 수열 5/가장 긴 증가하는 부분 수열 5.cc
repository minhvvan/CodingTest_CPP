#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;
vector<int> dp;
vector<int> L;
vector<int> ans;
int len;
const int MAX = 1'000'000'001;


int main()
{
	INPUT_OPTIMIZE;

	cin >> N;
	nums.resize(N);
	dp.resize(N, 0);
	L.resize(N, MAX);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < N; i++)
	{
		int pos = lower_bound(L.begin(), L.begin() + len, nums[i]) - L.begin();
		dp[i] = pos;

		if (pos + 1 > len) len++;
		L[pos] = nums[i];
	}

	int LIS = len - 1;

	for (int i = N - 1; i >= 0; i--)
	{
		if (dp[i] == LIS)
		{
			ans.push_back(nums[i]);
			LIS--;
		}
	}

	int size = ans.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
	{
		cout << ans.back() << " ";
		ans.pop_back();
	}

	return 0;
}