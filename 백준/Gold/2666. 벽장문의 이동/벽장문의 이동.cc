#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
int open1, open2;
vector<int> order;
const int MAX = 987654321;
int ans = MAX;

int MoveDoor(vector<int>& doors, int start, bool bLeft)
{
	int cnt = 0;
	if (bLeft)
	{
		int nearBlank = start;
		for (int i = start; i > 0; i--)
		{
			if (doors[i] == 0)
			{
				nearBlank = i;
				break;
			}

			cnt++;
		}

		if (nearBlank == start)
		{
			cnt = MAX;
		}
		else
		{
			doors[nearBlank] = 1;
			doors[start] = 0;
		}
	}
	else
	{
		int nearBlank = start;

		for (int i = start; i <= N; i++)
		{
			if (doors[i] == 0)
			{
				nearBlank = i;
				break;
			}
			cnt++;
		}

		if (nearBlank == start)
		{
			cnt = MAX;
		}
		else
		{
			doors[nearBlank] = 1;
			doors[start] = 0;
		}
	}

	return cnt;
}

void DFS(vector<int>& doors, int depth, int moves)
{
	if (depth == order.size())
	{
		ans = min(ans, moves);
		return;
	}

	if (!doors[order[depth]])
	{
		DFS(doors, depth + 1, moves);
	}
	else
	{
		//왼쪽으로 밀기
		{
			auto copied = doors;
			int leftMove = MoveDoor(copied, order[depth], true);
			if (ans > moves + leftMove)
			{
				DFS(copied, depth + 1, moves + leftMove);
			}
		}

		//오른쪽으로 밀기
		{
			auto copied = doors;
			int rightMove = MoveDoor(copied, order[depth], false);
			if (ans > moves + rightMove)
			{
				DFS(copied, depth + 1, moves + rightMove);
			}
		}
	}
}


int main()
{
	INPUT_OPTIMIZE;

	cin >> N;
	cin >> open1 >> open2;

	/*
	* 1 1 0 1 0 1 1 1
	* 
	*/

	int temp;
	cin >> temp;

	order.resize(temp);
	for (int i = 0; i < temp; i++)
	{
		cin >> order[i];
	}

	vector<int> doors(N + 1, 1);

	doors[open1] = 0;
	doors[open2] = 0;

	DFS(doors, 0, 0);

	cout << ans;

	return 0;
}