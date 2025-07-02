#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> temp;
	for (int i = 0; i < N; i++)
	{
		int op;
		cin >> op;

		switch (op)
		{
		case 1:
			int num;
			cin >> num;
			temp.push_back(num);
			break;
		case 2:
			if (!temp.empty())
			{
				auto n = temp.back();
				temp.pop_back();
				cout << n << "\n";
			}
			else cout << -1 << "\n";
			break;
		case 3:
			cout << temp.size() << "\n";
			break;
		case 4:
			if (temp.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 5:
			if (!temp.empty()) cout << temp.back() << "\n";
			else cout << -1 << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}