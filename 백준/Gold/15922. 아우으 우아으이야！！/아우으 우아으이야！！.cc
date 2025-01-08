#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> lines;
const int MIN = -1'000'000'001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		lines.push_back({ a,b });
	}

	//연속적인지 판단하고
	//연속이면 right만 갱신
	//연속적이지 않으면 ans에 더하고 left right 갱신
	long long ans = 0;
	auto [left, right] = lines[0];
	for (int i = 1; i < N ; i++)
	{
		auto [x, y] = lines[i];

		if (left <= x && y <= right) continue;

		if (x <= right)
		{
			right = y;
		}
		else
		{
			ans += right - left;
			left = x;
			right = y;
		}
	}

	ans += right - left;
	cout << ans;

	return 0;
}