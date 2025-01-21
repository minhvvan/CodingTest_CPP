#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> lectures;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		lectures.push_back({ b,c });
	}

	sort(lectures.begin(), lectures.end());
		
	auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
		};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < N; i++)
	{
		auto& [start, end] = lectures[i];

		if (pq.empty())
		{
			pq.push({ start, end });
			continue;
		}

		auto [s, e] = pq.top();
		if (e <= start)
		{
			pq.pop();
			pq.push({ s, end });
			continue;
		}

		pq.push({ start, end });
	}

	cout << pq.size();


	return 0;
}