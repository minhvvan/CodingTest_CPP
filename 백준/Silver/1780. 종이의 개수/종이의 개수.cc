#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> paper;
vector<int> answer(3, 0);

vector<int> dy = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
vector<int> dx = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

bool CheckSame(int startY, int startX, int size)
{
	int target = paper[startY][startX];

	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			if (paper[i][j] != target) return false;
		}
	}

	return true;
}

void Cut(int ulY, int ulX, int size)
{
	if (CheckSame(ulY, ulX, size))
	{
		answer[paper[ulY][ulX] + 1]++;
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		int y = ulY + dy[i] * size / 3;
		int x = ulX + dx[i] * size / 3;

		Cut(y, x, size / 3);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	paper.resize(N+1, vector<int>(N+1));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> paper[i][j];
		}
	}

	Cut(1, 1, N);

	for (auto ans : answer)
	{
		cout << ans << "\n";
	}

	return 0;
}