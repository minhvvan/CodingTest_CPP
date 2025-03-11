#include <bits/stdc++.h>
using namespace std;

long long A, B;
set<int> visited;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	queue<pair<int,int>> q;
	q.push({B, 1});

	int ans = INT_MAX;

	while (!q.empty())
	{
		auto [num, cnt] = q.front();
		q.pop();

		if (num % 2 == 0)
		{
			long long mult = num / 2;
			if (mult > 0)
			{
				if (mult == A) ans = min(ans, cnt + 1);
				if (visited.count(mult) == 0)
				{
					visited.insert(mult);
					q.push({ mult, cnt + 1 });
				}
			}
		}

		if (num % 10 == 1)
		{
			long long plus = num / 10;
			if (plus > 0)
			{
				if (plus == A) ans = min(ans, cnt + 1);
				if (visited.count(plus) == 0)
				{
					visited.insert(plus);
					q.push({ plus, cnt + 1 });
				}
			}
		}
	}

	if (ans == INT_MAX) cout << -1;
	else cout << ans;

	return 0;
}