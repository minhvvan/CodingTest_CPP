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


	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < M; j++)
		{
			int dist = abs(x - shootPoints[j]);
			dist += y;

			if (dist <= L)
			{
				ans++;
				break;
			}
		}
	}

	cout << ans;

	return 0;
} 