#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> houses;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	houses.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> houses[i];
	}

	sort(houses.begin(), houses.end());
	cout << houses[(N - 1) / 2];

	return 0;
}