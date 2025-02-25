#include <bits/stdc++.h>

using namespace std;

string S;
int q;

vector<vector<int>> Count;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> S >> q;

	Count.resize(26, vector<int>());

	for (int i = 0; i < S.length(); i++)
	{
		int idx = S[i] - 'a';
		Count[idx].push_back(i);
	}

	while (q--)
	{
		char c;
		int l, r;
		cin >> c >> l >> r;

		int alpha = c - 'a';
		int start = lower_bound(Count[alpha].begin(), Count[alpha].end(), l) - Count[alpha].begin();
		int end = upper_bound(Count[alpha].begin(), Count[alpha].end(), r) - Count[alpha].begin();

		cout << end - start << "\n";
	}

	
	return 0;
}