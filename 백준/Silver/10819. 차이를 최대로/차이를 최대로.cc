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
	
	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int ans = 0;

	do 
	{
		int sum = 0;

		for (int i = 0; i < N - 1; i++)
		{
			sum += abs(nums[i] - nums[i + 1]);
		}

		ans = max(ans, sum);

	} while (next_permutation(nums.begin(), nums.end()));


	cout << ans;


	return 0;
}