#include <bits/stdc++.h>
using namespace std;

int N, M, B;
vector<vector<int>> board;
map<int, int> heightCnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> M >> B;
	board.resize(N, vector<int>(M));
	//시간과 높이 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			heightCnt[board[i][j]]++;
		}
	}

	int maxheight = 0;
	int time = INT_MAX;

	for (int i = 0; i <= 256; i++)
	{
		int result = 0;
		int fillCnt = 0;
		int cutCnt = 0;

		for (auto [h, cnt] : heightCnt)
		{
			int diff = h - i;
			if (diff < 0)
			{
				//채우기
				fillCnt += abs(diff) * cnt;
			}
			else
			{
				//깎기
				cutCnt += diff * cnt;
			}
		}

		if (fillCnt > cutCnt + B) continue;

		int temp = fillCnt + cutCnt * 2;
		if (temp <= time)
		{
			time = temp;
			maxheight = i;
		}
	}

	cout << time << " " << maxheight;

	return 0;
}