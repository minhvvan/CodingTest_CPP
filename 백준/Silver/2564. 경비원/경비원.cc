#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
int T;

vector<pair<int, int>> shops;
pair<int, int> pos;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> N >> M >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;

		shops.push_back({ a,b });
	}

	{
		int a, b;
		cin >> a >> b;
		pos = { a,b };
	}

	/*
	* 시계 아니면 반시계로 돌아보면 될듯
	* 
	* 동, 서 = 위쪽을 기준으로 떨어진 거리
	* 남, 북 = 왼쪽을 기준으로 떨어진 거리
	* 
	* 북 남 서 동 
	* 
	* 전체 둘레 = 시계 + 반시계
	* 최소
	* 서 & 남 => 세로 - 좌표 + 좌표
	* 동 & 남 => 세로 - 좌표 + 가로 - 좌표
	* 서 & 북 => 좌표 + 좌표
	* 동 & 북 => 좌표 + 가로 - 좌표
	* 같은 곳 => abs(좌표 - 좌표)
	* 마주 봄 => min(좌표 + 좌표 + 다른쪽 길이, 전체 - 앞에 계산)
	*/
	
	int ans = 0;
	int total = 2 * N + 2 * M;
	for (int i = 1; i <= total; i++)
	{
		if (pos.first == 1 || pos.first == 4) pos.second++;
		else pos.second--;

		if (pos.second == 0)
		{
			if (pos.first == 2) 
			{
				pos.first = 3;
				pos.second = M;
			}
			else if(pos.first == 3)
			{
				pos.first = 1;
			}
		}
		
		if(pos.second == N)
		{
			if (pos.first == 1)
			{
				pos.first = 4;
				pos.second = 0;
			}
		}
		
		if(pos.second == M)
		{
			if (pos.first == 4)
			{
				pos.first = 2;
				pos.second = N;
			}
		}

		for (auto& shop : shops)
		{
			if (shop == pos)
			{
				ans += min(i, total - i);
			}
		}
	}

	cout << ans;

	return 0;
}