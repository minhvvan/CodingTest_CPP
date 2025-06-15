#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> cards;
vector<vector<int>> dp;
const int MAX = 987654321;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	cards.resize(N + 1);
	dp.resize(N + 1, vector<int>(N + 1, MAX));

	for (int i = 1; i <= N; i++)
	{
		cin >> cards[i];
	}

	/*
	* 1 5 6 7
	* 
	* 
	* 1 2 3 4 5 6 7
	* 
	*/

	for (int i = 0; i <= N; i++) dp[i][0] = 0;

	for (int i = 1; i <= N; i++)
	{
		//i번 카드를 사용하여 만들 수 있는 값들
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);

			int k = 1;
			while (k * i <= j)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - k * i] + k * cards[i]);
				k++;
			}
		}
	}

	cout << dp[N][N];

	return 0;
}