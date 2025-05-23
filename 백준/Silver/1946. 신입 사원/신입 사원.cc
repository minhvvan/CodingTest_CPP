#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, N;
vector<pair<int, int>> people;

int main() 
{
    INPUT_OPTIMIZE;
    
	cin >> T;

	/*
	* 
		1 4 o
		2 5 x
		3 6 x
		4 2 o
		5 7 x
		6 1 o
		7 3 x
	* 
	*/

	while (T--)
	{
		cin >> N;

		people.clear();

		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;

			people.push_back({ a,b });
		}

		sort(people.begin(), people.end());

		int cnt = 0;
		priority_queue<int> pq;

		for (int i = 0; i < N; i++)
		{
			auto [a, b] = people[i];
			
			if (pq.empty())
			{
				cnt++;
			}
			else
			{
				auto top = pq.top();
				top *= -1;
				if (top > b)
				{
					cnt++;
				}
			}

			pq.push(-b);
		}

		cout << cnt << "\n";
	}

	return 0;
} 