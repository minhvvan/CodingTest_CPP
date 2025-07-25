#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<pair<int, int>> elements;

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int s, b;
		cin >> s >> b;

		elements.push_back({ s, b });
	}

	long long ans = LLONG_MAX;

	for (int i = 1; i < (1 << N); i++)
	{
		long long S = 1;
		long long B = 0;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				S *= elements[j].first;
				B += elements[j].second;
			}
		}

		ans = min(ans, abs(S - B));
	}

	cout << ans;
}