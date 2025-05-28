#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int M, N, L;
vector<int> shootPoints;

int main()
{
    INPUT_OPTIMIZE;

	cin >> M >> N >> L;
	shootPoints.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> shootPoints[i];
	}

	sort(shootPoints.begin(), shootPoints.end());

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		int dist = L - y;
		if (dist < 0) continue;

		//왼쪽 탐색
		auto leftIdx = lower_bound(shootPoints.begin(), shootPoints.end(), x - dist) - shootPoints.begin();
		auto rightIdx = upper_bound(shootPoints.begin(), shootPoints.end(), x + dist) - shootPoints.begin();
		if (leftIdx < rightIdx)
		{
			ans++;
		}
	}

	cout << ans;

	return 0;
} 