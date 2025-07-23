#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
string input;
set<string> ans;

int main()
{
	INPUT_OPTIMIZE;

	cin >> input;
	int N = input.length();

	for (int i = 1; i <= input.length(); i++)
	{
		for (int j = 0; j <= N - i; j++)
		{
			auto temp = input.substr(j, i);
			ans.insert(temp);
		}
	}

	cout << ans.size();
	
}