#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<int> positive, negative;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num <= 0)
		{
			negative.push_back(num);
		}
		else
		{
			if (num == 1) ans += num;
			else positive.push_back(num);
		}
	}

	sort(negative.begin(), negative.end(), greater<int>());
	sort(positive.begin(), positive.end());

	while (negative.size() > 1)
	{
		int a = negative.back();
		negative.pop_back();

		int b = negative.back();
		negative.pop_back();

		ans += a * b;
	}

	while (!negative.empty())
	{
		ans += negative.back();
		negative.pop_back();
	}

	while (positive.size() > 1)
	{
		int a = positive.back();
		positive.pop_back();

		int b = positive.back();
		positive.pop_back();

		ans += a * b;
	}

	while (!positive.empty())
	{
		ans += positive.back();
		positive.pop_back();
	}

	cout << ans;

	return 0;
}