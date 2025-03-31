#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, C;

struct Nums
{
	Nums()
	{
		idx = -INF;
		cnt = 0;
	}

	Nums(int i, int c) : idx(i), cnt(c) {};

	int idx;
	int cnt;
};

map<int, Nums> nums;
vector<pair<int, Nums>> result;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (nums[num].cnt != 0) nums[num].cnt++;
		else
		{
			nums[num].idx = i;
			nums[num].cnt = 1;
		}
	}

	for (auto& num : nums)
	{
		result.push_back({ num.first, num.second });
	}

	sort(result.begin(), result.end(), [](pair<int, Nums>& a, pair<int, Nums>& b) {
		if (a.second.cnt == b.second.cnt) return a.second.idx < b.second.idx;
		return a.second.cnt > b.second.cnt;
		});

	for (auto& [num, info] : result)
	{
		for (int i = 0; i < info.cnt; i++)
		{
			cout << num << " ";
		}
	}

	return 0;
}