#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> money;

int GetCount(int k)
{
	int cnt = 1;
	int m = k;
	for (int i = 0; i < N; i++)
	{
		if (money[i] <= m)
		{
			m -= money[i];
		}
		else
		{
			cnt++;
			m = k;
			m -= money[i];
		}
	}

	return cnt;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	money.resize(N);

	int left = 0;
	int right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		right += money[i];
		left = max(left, money[i]);
	}

	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = GetCount(mid);

		if (cnt > M)
		{
			left = mid + 1;
		}
		else
		{
			ans = min(ans, mid);
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}