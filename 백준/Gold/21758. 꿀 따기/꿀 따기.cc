#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> honey;
vector<int> sum;

int main(int args)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	honey.resize(N + 1);
	sum.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> honey[i];
		sum[i] = sum[i - 1] + honey[i];
	}

	int ans = 0;

	for (int i = 2; i < N; i++) {
		//벌벌꿀
		ans = max(ans, 2 * sum[N] - honey[1] - honey[i] - sum[i]);

		//꿀벌벌
		ans = max(ans, sum[N - 1] - honey[i] + sum[i - 1]);

		//벌꿀벌
		ans = max(ans, sum[i] - honey[1] + sum[N - 1] - sum[i - 1]);
	}

	cout << ans;

	return 0;
}