#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> words;
vector<pair<int,char>> alpha(26);
vector<int> value(26);

int MakeNum(string word)
{
	int result = 0;
	for (int i = 0; i < word.length(); i++)
	{
		result *= 10;
		result += value[word[i] - 'A'];
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		words.push_back(str);
	}

	for (int i = 0; i < N; i++)
	{
		int len = words[i].length();
		for (int j = 0; j < len; j++)
		{
			int letterIdx = words[i][j] - 'A';
			alpha[letterIdx].first += pow(10, len - j);
			alpha[letterIdx].second = words[i][j];
		}
	}

	sort(alpha.begin(), alpha.end(), greater<pair<int, char>>());

	int v = 9;
	for (auto& [order, letter] : alpha)
	{
		if (v < 0 || letter < 'A') break;
		value[letter - 'A'] = v--;
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += MakeNum(words[i]);
	}

	cout << ans;

	return 0;
}