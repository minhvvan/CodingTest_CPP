#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<string> friends;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	friends.resize(N);

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> friends[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (friends[i][j] == 'Y')
			{
				cnt++;
			}
			else
			{
				for (int k = 0; k < N; k++)
				{
					if (k == i) continue;

					if (friends[k][j] == 'Y' && friends[i][k] == 'Y')
					{
						cnt++;
						break;
					}
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}