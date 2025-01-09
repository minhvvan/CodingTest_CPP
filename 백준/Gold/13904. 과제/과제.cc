#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> Tasks;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	vector<bool> days(1001, false);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		Tasks.push_back({ a,b });
	}

	sort(Tasks.begin(), Tasks.end(), [](auto& a, auto& b) -> bool
		{
			return a.second > b.second;
		});

	int ans = 0;
	for (auto& [deadline, score] : Tasks)
	{
		for (int i = deadline; i > 0; i--)
		{
			if (days[i] == false)
			{
				days[i] = true;
				ans += score;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}