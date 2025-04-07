#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
const int MAX = 1001;
vector<int> visited(MAX, INT_MAX);

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

	vector<bool> visit(MAX, false);

	queue<tuple<int, int, int>> q;
	q.push({ 1,0, 0 });

	while (!q.empty()) 
	{
		auto [screen, clip, time] = q.front();
		q.pop();

		if (screen == N)
		{
			cout << time;
			return 0;
		}

		//복사
		if (!visit[screen])
		{
			visit[screen] = 1;
			q.push({ screen, screen, time + 1 });
		}

		//붙여넣기
		if (screen + clip <= N)
		{
			q.push({ screen + clip, clip, time + 1 });
		}

		//지우기
		if (screen - 1 >= 0)
		{
			q.push({ screen - 1, clip, time + 1 });
		}
	}

    return 0;
}