#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int M, N;
vector<int> snacks;

bool Check(int mid)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt += snacks[i] / mid;
	}

	return M <= cnt;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> M >> N;
	snacks.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> snacks[i];
	}

	sort(snacks.begin(), snacks.end());

	int left = 1;
	int right = snacks.back();

	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (Check(mid))
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}