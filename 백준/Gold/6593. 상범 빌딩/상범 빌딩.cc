#include <bits/stdc++.h>

using namespace std;

int L, R, C;
char building[31][31][31];
vector<int> dl = { -1, 1, 0, 0, 0, 0 };
vector<int> dy = { 0, 0, -1, 0, 1, 0 };
vector<int> dx = { 0, 0, 0, 1, 0, -1 };

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;


	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		tuple<int, int, int> pos;

		for (int l = 0; l < L; l++)
		{
			for (int i = 0; i < R; i++)
			{
				string str;
				cin >> str;

				for (int j = 0; j < C; j++)
				{
					building[l][i][j] = str[j];
					if (building[l][i][j] == 'S')
					{
						pos = { l,i,j };
					}
				}
			}
		}

		bool visited[31][31][31] = { false, };

		queue<tuple<int, int, int>> q;
		q.push(pos);
		visited[get<0>(pos)][get<1>(pos)][get<2>(pos)] = true;

		bool flag = false;
		int cnt = 0;

		while (!q.empty())
		{
			int size = q.size();
			cnt++;

			for (int t = 0; t < size; t++)
			{
				auto [l, y, x] = q.front();
				q.pop();

				for (int i = 0; i < 6; i++)
				{
					int newL = l + dl[i];
					int newY = y + dy[i];
					int newX = x + dx[i];

					if (newL < 0 || newL >= L || newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
					if (building[newL][newY][newX] == '#') continue;
					if (visited[newL][newY][newX]) continue;
					visited[newL][newY][newX] = true;

					if (building[newL][newY][newX] == 'E')
					{
						cout << "Escaped in " << cnt << " minute(s).\n";
						flag = true;
						break;
					}

					q.push({ newL, newY, newX });
				}

				if (flag) break;
			}
		}

		if (!flag) cout << "Trapped!\n";
	}

	return 0;
}