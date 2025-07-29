#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, ans = 0;
vector<int> counts;

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;
	counts.resize(10, 0);

	int category = 0;
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		q.push(x);
		
		if (counts[x] == 0) category++;
		counts[x]++;

		while (category > 2)
		{
			auto front = q.front();
			q.pop();

			if (--counts[front] == 0)
			{
				category--;
			}
		}

		ans = max(ans, (int)q.size());
	}

	cout << ans;
}