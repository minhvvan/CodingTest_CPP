#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<int> line;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	line.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> line[i];
	}

	vector<int> temp;

	int current = 1;
	for (int i = 0; i < N; i++)
	{
		if (current != line[i])
		{
			temp.push_back(line[i]);
			continue;
		}

		current++;
		while (!temp.empty())
		{
			if (temp.back() == current)
			{
				temp.pop_back();
				current++;
				continue;
			}

			break;
		}
	}
	
	if (temp.empty()) cout << "Nice";
	else cout << "Sad";

	return 0;
}