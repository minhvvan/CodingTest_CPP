#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;

vector<int> types;
deque<int> nums;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int type;
		cin >> type;

		types.push_back(type);
	}

	for (int i = 0; i < N; i++)
	{
		int prev;
		cin >> prev;

		if (types[i] == 1) continue;
		nums.push_back(prev);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		nums.push_front(num);

		int result = nums.back();
		nums.pop_back();

		cout << result << " ";
	}

	return 0;
}