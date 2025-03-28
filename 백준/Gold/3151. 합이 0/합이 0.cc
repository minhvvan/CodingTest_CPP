#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

vector<int> abilities;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N;
	abilities.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> abilities[i];
	}

	sort(abilities.begin(), abilities.end());

	long long ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int a = abilities[i];
			int b = abilities[j];

			int sum = a + b;

			int pos = lower_bound(abilities.begin() + j + 1, abilities.end(), -sum) - abilities.begin();
			int pos2 = upper_bound(abilities.begin() + j + 1, abilities.end(), -sum) - abilities.begin();

			if (pos < abilities.size() && abilities[pos] == -sum)
			{
				ans += pos2 - pos;
			}
		}
	}

	cout << ans;

	return 0;
}