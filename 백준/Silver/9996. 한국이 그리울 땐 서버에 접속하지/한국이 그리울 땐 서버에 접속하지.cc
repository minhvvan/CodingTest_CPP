#include <bits/stdc++.h>
using namespace std;

int N;

string origin, pre, suf;
vector<string> files;

void Match(string str)
{
	if (str.size() < pre.size() + suf.size()) 
	{
		cout << "NE" << "\n";
	}
	else 
	{
		if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size()))
		{
			cout << "DA" << "\n";
		}
		else
		{
			cout << "NE" << "\n";
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	files.resize(N);

	cin >> origin;
	for (int i = 0; i < N; i++)
	{
		cin >> files[i];
	}

	int pos = origin.find('*');
	pre = origin.substr(0, pos);
	suf = origin.substr(pos + 1);

	for (int i = 0; i < N; i++)
	{
		Match(files[i]);
	}

	return 0;
}