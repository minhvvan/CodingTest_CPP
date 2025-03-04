#include <bits/stdc++.h>

using namespace std;

int N, ATK;
vector<tuple<int, int, int>> dungeon;

bool CheckPossible(long long maxHP)
{
	long long currentAtk = ATK;
	long long currentHP = maxHP;
	for (int i = 0; i < N; i++)
	{
		auto [type, attack, health] = dungeon[i];

		if (type == 1)
		{
			long long cnt = health / currentAtk;
			if (health % currentAtk) cnt++;

			currentHP -= attack * (cnt - 1);
			if (currentHP <= 0) return false;
		}
		else
		{
			currentAtk += attack;
			currentHP = min(maxHP, currentHP + health);
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> ATK;

	for (int i = 0; i < N; i++)
	{
		int t, a, h;
		cin >> t >> a >> h;

		dungeon.push_back({ t, a, h });
	}

	/*
	* 순차적으로 처리해야 함
	* 이진 탐색
	* N번만에 가능여부 판단 가능
	*/
	long long left = 1;
	long long right = LLONG_MAX;

	long long ans = right;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (CheckPossible(mid))
		{
			ans = min(ans, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;

	return 0;
}