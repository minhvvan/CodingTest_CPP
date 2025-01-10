#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	nums.resize(N);

	if (N == 1)
	{
		cout << "A";
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	//다음 수를 출력한다. 만약 다음 수가 여러 개일 경우에는 A를 출력하고, 다음 수를 구할 수 없는 경우에는 B를 출력한다.
	set<int> answer;

	set<pair<int, int>> possible;
	{
		int current = nums[0];
		int next = nums[1];

		for (int a = -200; a <= 200; a++)
		{
			int b = current * a - next;
			possible.insert({ a,b });
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		int current = nums[i];
		int next = nums[i + 1];
		int diff = next - current;

		//current * a - b = next
		set<pair<int, int>> temp;
		for (auto& [a, b] : possible)
		{
			if (current * a - b == next)
			{
				temp.insert({ a,b });
			}
		}

		possible = move(temp);
	}

	int last = nums.back();
	for (auto& [a, b] : possible)
	{
		answer.insert(last * a - b);
	}

	int cnt = answer.size();
	if (cnt == 0)
	{
		cout << "B";
	}
	else if (cnt > 1)
	{
		cout << "A";
	}
	else
	{
		cout << *answer.begin();
	}

	return 0;
}