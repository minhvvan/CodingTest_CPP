#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>

using namespace std;

bool Dijk(vector<vector<pair<int, int>>>& Cable, int x, int N, int K) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(N + 1, INT_MAX);
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int current = pq.top().second;
		int currentCost = -1 * pq.top().first;

		pq.pop();

		if (dist[current] < currentCost) continue;

		for (int i = 0; i < Cable[current].size(); i++) {
			auto [next, nextCost] = Cable[current][i];

			// 핵심!!
			int w = currentCost + (nextCost > x);
			if (dist[next] > w) {
				dist[next] = w;
				pq.push(make_pair(-1 * w, next));
			}
		}
	}

	return dist[N] <= K;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, P, K;
    cin >> N >> P >> K;

    vector<vector<pair<int, int>>> Cable(N+1);

    for (int i = 0; i < P; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        Cable[a].push_back({ b, cost });
        Cable[b].push_back({ a, cost });
    }

	int l = 0, r = 1'000'000, ans = -1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (Dijk(Cable, mid, N, K)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;

    return 0;
}