#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;
vector<int> L;
int len = 0;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	nums.resize(N);
	L.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (auto num : nums)
	{
		int pos = lower_bound(L.begin(), L.begin() + len, num) - L.begin();
		L[pos] = num;

		if (pos >= len) len++;
	}

	cout << N - len;

	return 0;
}