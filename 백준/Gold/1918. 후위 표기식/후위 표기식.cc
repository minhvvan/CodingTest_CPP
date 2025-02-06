#include <bits/stdc++.h>

using namespace std;

string str;
vector<char> op;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> str;

	for (auto c : str)
	{
		if ('A' <= c && c <= 'Z')
		{
			cout << c;
			continue;
		}

		if (c == '(')
		{
			op.push_back('(');
			continue;
		}

		if (c == '-' || c == '+')
		{
			while (!op.empty() && op.back() != '(')
			{
				cout << op.back();
				op.pop_back();
			}

			op.push_back(c);
		}
		else if (c == '*' || c == '/')
		{
			while (!op.empty() && (op.back() == '*' || op.back() == '/'))
			{
				cout << op.back();
				op.pop_back();
			}

			op.push_back(c);
		}
		else if (c == ')')
		{
			while (!op.empty() && op.back() != '(')
			{
				cout << op.back();
				op.pop_back();
			}

			op.pop_back();
		}
	}

	while (!op.empty())
	{
		cout << op.back();
		op.pop_back();
	}

	return 0;
}