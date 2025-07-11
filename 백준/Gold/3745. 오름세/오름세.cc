#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<int> nums;

int main()
{
	INPUT_OPTIMIZE;
	
	while (cin >> N)
	{
		nums.clear();
		nums.resize(N);

		int len = 0;
		vector<int> L(N);

		for (int i = 0; i < N; i++)
		{
			cin >> nums[i];
		}

		for (int i = 0; i < N; i++)
		{
			auto pos = lower_bound(L.begin(), L.begin()+ len, nums[i]) - L.begin();

			L[pos] = nums[i];
			if (pos >= len)
			{
				len++;
			}
		}

		cout << len << "\n";
	}

	return 0;
}