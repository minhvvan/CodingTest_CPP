#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	
	nums.resize(N);
	answer.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	vector<int> stack;

	answer[N-1] = -1;
	stack.push_back(nums[N-1]);
	for (int i = N-2; i >= 0; i--)
	{
		int result = -1;
		while (!stack.empty() && stack.back() <= nums[i])
		{
			stack.pop_back();
		}

		if (!stack.empty()) result = stack.back();
		answer[i] = result;
		
		stack.push_back(nums[i]);
	}

	for (auto ans : answer)
	{
		cout << ans << " ";
	}


	return 0;
}