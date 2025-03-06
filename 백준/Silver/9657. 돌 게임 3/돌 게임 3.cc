#include <bits/stdc++.h>
using namespace std;

int N;
vector<bool> states;
vector<int> dx = { 1, 3, 4 };

int main(int args)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	states.resize(N + 1, false);

	states[0] = false;
	states[1] = true;
	states[2] = false;
	states[3] = true;
	states[4] = true;

	for (int i = 5; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//승리상태로 만들 수 있으면 승리상태
			int prev = i - dx[j];
			if (!states[prev]) states[i] = true;
		}
	}

	if (states[N]) cout << "SK";
	else cout << "CY";

	return 0;
}