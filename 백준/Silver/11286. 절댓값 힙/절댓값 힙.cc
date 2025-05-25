#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

struct cmp
{
	bool operator () (pair<int, int>& a, pair<int, int>& b)
	{
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

int main() 
{
    INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
				continue;
			}

			auto [absNum, num] = pq.top();
			pq.pop();

			cout << num << "\n";
		}
		else
		{
			if (x < 0)
			{
				pq.push({ x, x });
			}
			else
			{
				pq.push({ -x, x });
			}
		}
	}

	return 0;
} 