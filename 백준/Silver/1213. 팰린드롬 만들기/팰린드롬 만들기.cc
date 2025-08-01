#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
string str;
vector<int> spellCnt(26, 0);

int main()
{
	INPUT_OPTIMIZE;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		spellCnt[str[i] - 'A']++;
	}

	int odd = 0;
	char oddChar = ' ';
	for (auto spell = 'A'; spell <= 'Z'; spell++)
	{
		auto cnt = spellCnt[spell - 'A'];
		if (cnt % 2 == 1)
		{
			odd++;
			oddChar = spell;
		}
	}

	if (odd > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	string ans;
	for (auto spell = 'A'; spell <= 'Z'; spell++)
	{
		auto cnt = spellCnt[spell - 'A'];
		auto half = cnt / 2;

		for (int i = 0; i < half; i++)
		{
			ans += spell;
		}
	}

	auto rev = ans;
	reverse(rev.begin(), rev.end());

	if (odd == 1)
	{
		ans += oddChar;
	}
	ans += rev;

	cout << ans;

	return 0;
}