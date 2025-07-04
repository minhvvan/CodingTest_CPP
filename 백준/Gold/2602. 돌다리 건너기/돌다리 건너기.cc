#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
string target;
string angel, devil;
int bridgeLen;
int dp[101][2][21];

int DFS(int idx, int bridge, int spellIdx)
{
	if (spellIdx == target.length()) return 1;

	int& ret = dp[idx][bridge][spellIdx];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = idx; i < bridgeLen; i++)
	{
		if (bridge == 0)
		{
			if (devil[i] == target[spellIdx])
			{
				ret += DFS(i + 1, 1, spellIdx + 1);
			}
		}
		else
		{
			if (angel[i] == target[spellIdx])
			{
				ret += DFS(i + 1, 0, spellIdx + 1);
			}
		}
	}

	return ret;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> target >> devil >> angel;

	/*
	* 시작 위치를 d, a로 두번 탐색
	* dp가 맞음
	*/

	bridgeLen = devil.length();
	memset(dp, -1, sizeof(dp));

	int ans = DFS(0, 0, 0);
	ans += DFS(0, 1, 0);

	cout << ans;

	return 0;
}