#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<pair<int, int>> meetings;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		meetings.push_back({ s,e });
	}

	sort(meetings.begin(), meetings.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	pq.push(meetings[0].second);

	for (int i = 1; i < N; i++)
	{
		while (!pq.empty() && pq.top() <= meetings[i].first)
		{
			pq.pop();
		}

		pq.push(meetings[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;

	return 0;
}