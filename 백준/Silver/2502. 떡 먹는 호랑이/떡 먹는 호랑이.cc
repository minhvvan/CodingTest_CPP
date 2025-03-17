#include <bits/stdc++.h>
using namespace std;

int D, K;
vector<pair<int, int>> dnums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> D >> K;

	dnums.resize(D + 1);
	dnums[1] = { 1, 0 };
	dnums[2] = { 0, 1 };

	for (int i = 3; i <= D; i++)
	{
		dnums[i] = { dnums[i - 1].first + dnums[i - 2].first, dnums[i - 1].second + dnums[i - 2].second };
	}

	for (int i = 1; i <= 100'000; i++)
	{
		int x = i;
		int rest = K - dnums[D].first * x;
		if (rest % dnums[D].second == 0)
		{
			int y = rest / dnums[D].second;
			cout << x << "\n" << y;
			break;
		}
	}



	return 0;
}