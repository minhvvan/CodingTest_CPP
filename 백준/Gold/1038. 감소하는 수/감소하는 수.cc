#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> nums;

void dfs(long long num, int first, int digit)
{
	nums.push_back(num);
	for (int i = first + 1; i < 10; i++)
	{
		long long add = i * pow(10, digit);
		dfs(num + add, i, digit + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		dfs(i, i, 1);
	}

	sort(nums.begin(), nums.end());
	
	if (nums.size() <= N) cout << -1;
	else cout << nums[N];

	return 0;
}