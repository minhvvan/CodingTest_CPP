#include <bits/stdc++.h>

using namespace std;

int N;
const int MAX = 20 * 100'000 + 1;
vector<int> nums;
vector<bool> dp(MAX, false);
vector<bool> visited;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	nums.resize(N);
	visited.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		dp[nums[i]] = true;
	}

	/*
	* 부분집합?? -> 2^20 불가능
	* bfs + dp
	*/

	queue<pair<int,int>> q;
	for (int i = 0; i < N; i++)
	{
		q.push({ nums[i], i });
	}

	while (!q.empty())
	{
		auto [num, idx] = q.front();
		q.pop();

		for (int i = idx+1; i < N; i++)
		{
			dp[num + nums[i]] = true;
			q.push({ num + nums[i], i });
		}
	}

	for (int i = 1; i < MAX; i++)
	{
		if (!dp[i])
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}