#include <bits/stdc++.h>
using namespace std;

int N, T, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		deque<pair<int,int>> dq;
		priority_queue<int> count;
		for (int i = 0; i < N; i++)
		{
			int priority;
			cin >> priority;

			count.push(priority);
			dq.push_back({priority, i});
		}

		int cnt = 1;
		while (true)
		{
			auto [front, idx] = dq.front();
			dq.pop_front();

			if (front != count.top())
			{
				dq.push_back({front, idx});
			}
			else
			{
				if (idx == M)
				{
					cout << cnt << "\n";
					break;
				}
				count.pop();
				cnt++;
			}
		}
	}

	return 0;
}