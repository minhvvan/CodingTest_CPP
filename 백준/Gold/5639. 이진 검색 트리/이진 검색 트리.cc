#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;

void go(int st, int en) 
{
	if (st >= en) return;

	if (st == en - 1) 
	{
		cout << nums[st] << '\n';
		return;
	}

	int idx = st + 1;
	while (idx < en) 
	{
		if (nums[st] < nums[idx]) break;
		idx++;
	}

	go(st + 1, idx);
	go(idx, en);

	cout << nums[st] << '\n';
}

int main() 
{
    INPUT_OPTIMIZE;

	int num;
	while (cin >> num)
	{
		nums.push_back(num);
	}

	go(0, nums.size());

	return 0;
} 