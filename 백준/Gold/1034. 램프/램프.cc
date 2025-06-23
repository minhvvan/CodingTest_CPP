#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, K;
unordered_map<string, pair<int, int>> lamps;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		lamps[str].first++;
		
		if (lamps[str].second == 0)
		{
			int cnt = 0;
			for (int j = 0; j < M; j++)
			{
				if (str[j] == '0') cnt++;
			}

			lamps[str].second = cnt;
		}
	}

	cin >> K;

	int ans = 0;
	for (auto& [str, count] : lamps)
	{
		auto& [cnt, zero] = count;
		if (zero <= K && zero % 2 == K % 2)
		{
			ans = max(ans, cnt);
		}
	}

	cout << ans;

	return 0;
}