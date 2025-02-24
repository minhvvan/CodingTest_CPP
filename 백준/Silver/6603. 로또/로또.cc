#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> S;

void MakeComb(vector<int>& temp, int idx)
{
	if (temp.size() == 6)
	{
		for (auto num : temp)
		{
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < S.size(); i++)
	{
		temp.push_back(S[i]);
		MakeComb(temp, i + 1);
		temp.pop_back();
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	while (cin >> K)
	{
		S.clear();
		S.resize(K);

		for (int i = 0; i < K; i++)
		{
			cin >> S[i];
		}

		vector<int> temp;
		MakeComb(temp, 0);
		cout << "\n";
	}
	
	return 0;
}