#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

int T, N;
vector<int> logs;

int main()
{
    INPUT_OPTIMIZE;

	cin >> T;

	while (T--)
	{
		cin >> N;

		logs.clear();
		logs.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> logs[i];
		}

		sort(logs.begin(), logs.end());

		deque<int> dq;

		for (int i = 0; i < N; i++)
		{
			if (i % 2 == 0)
			{
				dq.push_back(logs[i]);
			}
			else
			{
				dq.push_front(logs[i]);
			}
		}

		int ans = abs(dq[0] - dq[N - 1]);
		for (int i = 1; i < N; i++)
		{
			ans = max(ans, abs(dq[i] - dq[i-1]));
		}

		cout << ans << "\n";
	}

	return 0;
} 