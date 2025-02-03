#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> nums;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		nums.push_back({ num, i });
	}

	sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		});

	int result = -1;

	for (int i = 0; i < N; i++)
	{
		if (result < nums[i].second - i)
		{
			result = nums[i].second - i;
		}
	}

	cout << result + 1;

	return 0;
}