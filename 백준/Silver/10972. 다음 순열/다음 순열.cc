#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	bool bInit = true;
	bool bComplete = false;

	do
	{
		if (bInit)
		{
			bInit = false;
			continue;
		}

		bComplete = true;

		for (auto num : nums)
		{
			cout << num << " ";
		}

		break;

	} while (next_permutation(nums.begin(), nums.end()));

	if (!bComplete) cout << -1;

	return 0;
}