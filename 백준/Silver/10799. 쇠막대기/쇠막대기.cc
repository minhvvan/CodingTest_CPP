#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
string stick;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> stick;
	
	vector<char> temp;
	char prev = ' ';

	int ans = 0;

	for (int i = 0; i < stick.length(); i++)
	{
		auto current = stick[i];

		if (current == '(')
		{
			temp.push_back(current);
		}
		else
		{
			if (prev == '(')
			{
				// 레이저
				temp.pop_back();
				ans += temp.size();
			}
			else
			{
				//막대 끝
				temp.pop_back();
				ans++;
			}
		}

		prev = current;
	}

	cout << ans;

	return 0;
}