#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> power;
int ans = INT_MAX;

void GetDiff(int team)
{
	//0이 한팀 1이 한팀
	int teamA = 0;
	int teamB = 0;
	for (int i = 0; i < N; i++)
	{
		int teamFlag = team & (1 << i);
		for (int j = 0; j < N; j++)
		{
			int temp = team & (1 << j);
			if (temp == 0)
			{
				if (teamFlag == 0) teamA += power[i][j];
			}
			else
			{
				if (teamFlag != 0) teamB += power[i][j];
			}
		}
	}

	ans = min(ans, abs(teamA - teamB));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	power.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> power[i][j];
		}
	}

	for (int i = 1; i < (1 << N); i++)
	{
		GetDiff(i);
	}
	
	cout << ans;

	return 0;
}