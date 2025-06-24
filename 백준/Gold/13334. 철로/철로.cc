#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, D;
vector<pair<int, int>> routes;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int h, o;
		cin >> h >> o;
		if (o < h) swap(h, o);
		routes.push_back({ h, o });
	}

	cin >> D;

	sort(routes.begin(), routes.end(), cmp);

	int start = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;

	for (auto& [h, o] : routes)
	{
		start = o - D;

		while (!pq.empty() && pq.top() < start) 
		{
			pq.pop();
		}

		if (h >= start) 
		{
			pq.push(h);
			ans = max(ans, (int)pq.size());
		}
	}
	
	cout << ans;

	return 0;
}