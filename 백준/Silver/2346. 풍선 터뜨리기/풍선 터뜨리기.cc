#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> balloon;
vector<bool> visited;

int main(int args)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	balloon.resize(N);
	visited.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		cin >> balloon[i];
	}

	int idx = 0;
	cout << idx + 1 << " ";
	visited[0] = true;

	for (int i = 0; i < N - 1; i++)
	{
		int offset = balloon[idx];
		int dir = offset < 0 ? -1 : 1;

		//offset만큼 이동
		for (int j = 0; j < abs(offset); j++)
		{
			idx = ((idx + dir) + N) % N;
			if (visited[idx]) j--;
		}

		visited[idx] = true;
		cout << idx + 1 << " ";
	}

	return 0;
}