#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
string str;
vector<int> bracket;

bool Pop(int type)
{
	int result = 0;
	int mult = 0;

	if (type == 0) mult = 2;
	else mult = 3;

	while (!bracket.empty())
	{
		auto top = bracket.back();
		bracket.pop_back();

		if (top == type)
		{
			if (result == 0) result = 1;
			bracket.push_back(result * mult);
			return true;
		}
		else
		{
			//올바르지 않은 괄호쌍
			if (top == 0 || top == 1)
			{
				cout << 0;
				exit(0);
			}

			result += top;
		}
	}

	return false;
}

int main() 
{
	INPUT_OPTIMIZE;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		auto current = str[i];
		if (current == '(')
		{
			bracket.push_back(0);
		}
		else if (current == '[')
		{
			bracket.push_back(1);
		}
		else if (current == ')')
		{
			if (!Pop(0))
			{
				cout << 0;
				return 0;
			}
		}
		else 
		{
			if (!Pop(1))
			{
				cout << 0;
				return 0;
			}
		}
	}

	int ans = 0;
	for (auto num : bracket)
	{
		if (num == 0 || num == 1)
		{
			cout << 0;
			return 0;
		}

		ans += num;
	}

	cout << ans;

	return 0;
}