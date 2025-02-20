#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> moves;

void Move(int from, int to, int n)
{
	if (n == 1)
	{
		moves.push_back({ from, to });
		return;
	}

	int another = (1 + 2 + 3) - from - to;

	Move(from, another, n - 1);
	Move(from, to, 1);
	Move(another, to, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;



	if (N <= 20)
	{
		Move(1, 3, N);

		cout << moves.size() << "\n";

		for (auto [from, to] : moves)
		{
			cout << from << " " << to << "\n";
		}
	}
	else
	{
		string str = to_string(pow(2, N));

		int a = str.find('.');
		str = str.substr(0, a);
		str[str.length() - 1] -= 1;

		cout << str << endl;
	}
	
	return 0;
}