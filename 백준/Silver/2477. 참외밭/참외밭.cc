#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int K;
vector<pair<int, int>> farm;

int main()
{
	INPUT_OPTIMIZE;

	cin >> K;

	int w = 0;
	int h = 0;

	int area = 0;
	farm.resize(12);

	for (int i = 0; i < 6; i++)
	{
		int d, l;
		cin >> d >> l;

		farm[i] = farm[i + 6] = { d,l };
	}


	for (int i = 3; i < 12; i++) 
	{
		if (farm[i - 3].first == farm[i - 1].first && farm[i - 2].first == farm[i].first)
		{
			area = farm[i + 1].second * farm[i + 2].second - farm[i - 1].second * farm[i - 2].second;
			break;
		}
	}

	cout << area * K;

	return 0;
}