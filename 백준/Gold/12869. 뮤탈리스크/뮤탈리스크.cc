#include <bits/stdc++.h>
using namespace std;

int n;
int dp[61][61][61];
int hp[3];
vector <vector<int>> v = 
{
	{1,3,9},
	{1,9,3},
	{3,1,9},
	{3,9,1},
	{9,1,3},
	{9,3,1}
};

int solution(int x, int y, int z)
{
	if (x == 0 && y == 0 && z == 0) return 0;

	int& res = dp[x][y][z];
	if (res != -1) return res;
	res = INT_MAX;

	for (int i = 0; i < 6; i++) 
	{
		int newX = max(0, x - v[i][0]);
		int newY = max(0, y - v[i][1]);
		int newZ = max(0, z - v[i][2]);

		res = min(res, solution(newX, newY, newZ) + 1);
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) cin >> hp[i];
	cout << solution(hp[0], hp[1], hp[2]) << "\n";

	return 0;
}