#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> alpha;
map<char, int> alphaIdx;
vector<string> ans;

void MakePwd(string current)
{
	if (current.length() == L)
	{
		int cntVowel = 0;
		int cntCons = 0;
		for (int i = 0; i < L; i++)
		{
			auto c = current[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cntVowel++;
			else cntCons++;
		}

		if (cntVowel >= 1 && cntCons >= 2)
		{
			ans.push_back(current);
		}

		return;
	}

	int start = current.length() == 0 ? 0 : alphaIdx[current.back()] + 1;
	for (int i = start; i < C; i++)
	{
		MakePwd(current + alpha[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;

		alpha.push_back(c);
	}

	sort(alpha.begin(), alpha.end());

	int idx = 0;
	for (auto c : alpha)
	{
		alphaIdx[c] = idx++;
	}

	string s;
	MakePwd(s);

	sort(ans.begin(), ans.end());

	for (auto str : ans)
	{
		cout << str << "\n";
	}

	return 0;
}