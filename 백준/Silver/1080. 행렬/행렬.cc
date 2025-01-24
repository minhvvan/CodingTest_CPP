#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<int>> origin;
vector<vector<int>> result;
set<vector<vector<int>>> checked;
const int MAX = 987'654'321;

void flip(vector<vector<int>>& arr, int y, int x)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			arr[i][j] = (arr[i][j] + 1) % 2;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	origin.resize(N, vector<int>(M));
	result.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			origin[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			result[i][j] = str[j] - '0';
		}
	}

	int ans = 0;
	for (int i = 0; i <= N-3; i++)
	{
		for (int j = 0; j <= M-3; j++)
		{
			if (origin[i][j] != result[i][j])
			{
				flip(origin, i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (origin[i][j] != result[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans;

	return 0;
}