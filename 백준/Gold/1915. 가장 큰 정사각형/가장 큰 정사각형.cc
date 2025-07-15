#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<string> grid;
vector<vector<int>> sum;
int ans = 0;

bool Check(int i, int j)
{
	int next = ans + 1;
	if (i + ans > N || j + ans > M) return false;
	return next * next == sum[i + ans][j + ans] - sum[i - 1][j + ans] - sum[i + ans][j - 1] + sum[i - 1][j - 1];
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;
	grid.resize(N);
	sum.resize(N + 1, vector<int>(M + 1, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> grid[i];
	}

	//가로
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sum[i][j] = sum[i][j - 1] + (grid[i-1][j-1] - '0');
		}
	}

	//세로
	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			sum[i][j] += sum[i - 1][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '0') continue;

			while (Check(i + 1, j + 1))
			{
				ans++;
			}
		}
	}

	cout << ans * ans;

	return 0;
}