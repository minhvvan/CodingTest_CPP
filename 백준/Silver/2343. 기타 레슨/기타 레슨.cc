#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> lectures;

bool Check(int capacity)
{
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum + lectures[i] > capacity)
		{
			cnt++;
			sum = 0;
		}

		sum += lectures[i];
	}

	if (sum != 0) cnt++;
	return cnt <= M;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;
	lectures.resize(N);

	int right = 0;
	int left = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> lectures[i];
		right += lectures[i];
		left = max(left, lectures[i]);
	}

	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (Check(mid))
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