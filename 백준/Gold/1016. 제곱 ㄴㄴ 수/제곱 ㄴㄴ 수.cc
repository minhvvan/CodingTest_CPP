#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
long long Min, Max;

vector<bool> dp(1000001, false);

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> Min >> Max;
	auto cnt = Max - Min + 1;

	for (long long i = 2; i * i <= Max; i++)
	{
		auto n = Min / (i * i);
		if (Min % (i * i)) n++;

		while (n * i * i <= Max)
		{
			if (!dp[n * i * i - Min])
			{
				cnt--;
				dp[n * i * i - Min] = true;
			}

			n++;
		}
	}

	cout << cnt;

	return 0;
}