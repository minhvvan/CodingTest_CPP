#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
vector<int> numCnt(1'000'001, 0);
vector<int> dp;

int GetRoot(int idx, int cnt)
{
	if (dp[idx] == -1 || cnt < numCnt[nums[idx]]) return idx;
	return GetRoot(dp[idx], cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	nums.resize(N);
	dp.resize(N, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		numCnt[nums[i]]++;
	}

	for (int i = N - 2; i >= 0; i--)
	{
		//오른쪽 수가 현재 수보다 많이 등장했을 때
		if (numCnt[nums[i]] < numCnt[nums[i + 1]])
		{
			dp[i] = i + 1;
		}
		else if (numCnt[nums[i]] == numCnt[nums[i + 1]])
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			int temp = GetRoot(i + 1, numCnt[nums[i]]);
			if (numCnt[nums[i]] < numCnt[nums[temp]]) dp[i] = temp;
		}
	}

	for (auto ans : dp)
	{
		if (ans == -1) cout << -1 << " ";
		else cout << nums[ans] << " ";
	}

	return 0;
}