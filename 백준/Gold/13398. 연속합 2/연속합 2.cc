#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;
vector<vector<int>> sums;
vector<int> sep;


int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	nums.resize(N);
	sums.resize(N, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	int ans = nums[0];

	sums[0][0] = nums[0];
	for (int i = 1; i < N; i++)
	{
		sums[i][0] = max(nums[i], sums[i - 1][0] + nums[i]);
		sums[i][1] = max(sums[i - 1][0], sums[i - 1][1] + nums[i]);

		ans = max(ans, sums[i][0]);
		ans = max(ans, sums[i][1]);
	}

	cout << ans;

	return 0;
}