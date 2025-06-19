#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
map<string, int> in;
vector<int> out;

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;
	int ans = 0;
	out.resize(N);

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		in[name] = i;
	}

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		out[i] = in[name];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (out[i] > out[j])
			{
				ans++;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}