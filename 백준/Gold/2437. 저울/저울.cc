#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> weights;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;
	weights.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> weights[i];
	}

	sort(weights.begin(), weights.end());

	int res = 1;
	for (int i = 0; i < N; i++) 
	{
		if (weights[i] > res) break;
		res += weights[i];
	}

	cout << res;
	
	return 0;
}