#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, H, W, Sr, Sc, Fr, Fc;
vector<vector<int>> board;
vector<vector<int>> sum;
vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool Check(int y, int x)
{
	int rightY = y + H - 1;
	int rightX = x + W - 1;

	if (rightY > N || rightX > M) return false;

	return sum[rightY][rightX] - sum[y - 1][rightX] - sum[rightY][x - 1] + sum[y - 1][x - 1] == 0;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;
	board.resize(N + 1, vector<int>(M + 1));
	sum.resize(N + 1, vector<int>(M + 1));
	visited.resize(N + 1, vector<bool>(M + 1, false));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sum[i][j] = sum[i][j - 1] + board[i][j];
		}
	}

	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			sum[i][j] += sum[i - 1][j];
		}
	}

	
	visited[Sr][Sc] = true;
	queue<pair<int, int>> q;
	q.push({ Sr, Sc });
	int depth = 1;
	bool bEnd = false;

	while (!q.empty())
	{
		auto size = q.size();
		for (int k = 0; k < size; k++)
		{
			auto [y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dy[i];
				int newX = x + dx[i];

				if (newY <= 0 || newY > N || newX <= 0 || newX > M) continue;
				if (visited[newY][newX]) continue;
				if (!Check(newY, newX)) continue;

				if (newY == Fr && newX == Fc)
				{
					bEnd = true;
					break;
				}

				visited[newY][newX] = true;
				q.push({ newY, newX });
			}

			if (bEnd) break;
		}

		if (bEnd) break;
		depth++;
	}

	if (bEnd) cout << depth;
	else cout << -1;

	return 0;
}