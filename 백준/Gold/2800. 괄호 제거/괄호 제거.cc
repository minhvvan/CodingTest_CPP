#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

string str;
set<string> answers;

void DFS(int depth, string current)
{
	if (depth == str.length())
	{
		if (current != str)
		{
			answers.insert(current);
		}
		return;
	}

	// 제거하는 경우
	if (str[depth] == ')')
	{
		string sub = "";

		int i = current.length() - 1;
		int closeCnt = 0;
		for (; i >= 0; i--)
		{
			if (current[i] == '(')
			{
				if (closeCnt != 0)
				{
					closeCnt--;
					continue;
				}

				sub = current.substr(i + 1, current.length() - i - 1);
				break;
			}
			else if (current[i] == ')')
			{
				closeCnt++;
			}
		}

		auto frontStr = current.substr(0, i);
		frontStr += sub;
		DFS(depth + 1, frontStr);
	}

	// 아닌 경우
	current += str[depth];
	DFS(depth + 1, current);
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> str;

	string temp;
	DFS(0, temp);

	for (auto& ans : answers)
	{
		cout << ans << "\n";
	}

	return 0;
}