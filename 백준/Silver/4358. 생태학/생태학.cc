#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
map<string, int> trees;

int main()
{
	INPUT_OPTIMIZE;
	
	string input;

	int total = 0;
	while (getline(cin, input))
	{
		trees[input]++;
		total++;
	}

	cout << fixed;
	cout.precision(4);


	for (auto [name, cnt] : trees)
	{
		cout << name << " " << (float)cnt * 100 / total << "\n";
	}

	

	return 0;
}