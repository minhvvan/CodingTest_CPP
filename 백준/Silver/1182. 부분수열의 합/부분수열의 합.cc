#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> S;

	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	int cnt = 0;

	for (int i = 1; i < (1 << N); i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				sum += nums[j];
			}
		}

		if (sum == S) cnt++;
	}

	cout << cnt;

	return 0;
}