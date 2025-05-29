#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int A, B, C;
set<int> answers;
bool visited[201][201][201] = { false, };

void DFS(int a, int b, int c)
{
	if (visited[a][b][c]) return;
	visited[a][b][c] = true;

	if (a == 0)
	{
		answers.insert(c);
	}

	if (a > 0)
	{
		//a -> b
		{
			int water = min(B - b, a);
			if (water > 0)
			{
				DFS(a - water, b + water, c);
			}
		}

		//a -> c
		{
			int water = min(C - c, a);
			if (water > 0)
			{
				DFS(a - water, b, c + water);
			}
		}
	}

	if (b > 0)
	{
		//b -> a
		{
			int water = min(A - a, b);
			if (water > 0)
			{
				DFS(a + water, b - water, c);
			}
		}

		//b -> c
		{
			int water = min(C - c, b);
			if (water > 0)
			{
				DFS(a, b - water, c + water);
			}
		}
	}
	

	if (c > 0)
	{
		//c -> a
		{
			int water = min(A - a, c);
			if (water > 0)
			{
				DFS(a + water, b, c - water);
			}
		}

		//c -> b
		{
			int water = min(B - b, c);
			if (water > 0)
			{
				DFS(a, b + water, c - water);
			}
		}
	}
	
}

int main()
{
    INPUT_OPTIMIZE;

	cin >> A >> B >> C;

	DFS(0, 0, C);

	for (auto ans : answers)
	{
		cout << ans << " ";
	}

	return 0;
} 