#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<long long> jewels;

bool check(long long mid)
{
	if (mid == 0) return false;

	int cnt = 0;
	for (auto jewel : jewels)
	{
		cnt += jewel / mid;
		if (jewel % mid != 0) cnt++;
	}

	return cnt <= N;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	jewels.resize(M);

	long long left = 0;
	long long right = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> jewels[i];
		right = max(right, jewels[i]);
	}

	long long ans = LLONG_MAX;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (check(mid))
		{
			ans = min(ans, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;


	return 0;
}