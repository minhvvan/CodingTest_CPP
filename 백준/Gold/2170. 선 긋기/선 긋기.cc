#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> lines;
const int MIN = -1'000'000'001;

int main() 
{
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

	sort(lines.begin(), lines.end());

	int left = lines[0].first;
	int right = lines[0].second;

	long long ans = 0;

	for (int i = 1; i < N; i++)
	{
		auto& [l, r] = lines[i];

		if (l <= right)
		{
			right = max(right, r);
			continue;
		}

		ans += right - left;
		left = l;
		right = r;
	}

	ans += right - left;

	cout << ans;

	return 0;
}