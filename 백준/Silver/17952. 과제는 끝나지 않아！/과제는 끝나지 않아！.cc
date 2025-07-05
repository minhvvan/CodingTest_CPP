#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	vector<pair<int, int>> tasks;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a;

		if (a == 0)
		{
			if (tasks.empty()) continue;
			auto& [score, time] = tasks.back();
			if (--time == 0)
			{
				ans += score;
				tasks.pop_back();
			}
		}
		else
		{
			cin >> b >> c;
			if (--c == 0)
			{
				ans += b;
			}
			else
			{
				tasks.push_back({ b, c });
			}
		}
	}

	cout << ans;

	
	return 0;
}