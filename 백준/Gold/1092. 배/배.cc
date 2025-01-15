#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> cranes;
vector<int> idx;
vector<int> boxes;
vector<bool> checked;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	cranes.resize(N);
	idx.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> cranes[i];
	}

	cin >> M;
	boxes.resize(M);
	checked.resize(M, false);

	for (int i = 0; i < M; i++)
	{
		cin >> boxes[i];
	}

	sort(cranes.begin(), cranes.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());

	if (cranes[0] < boxes[0])
	{
		cout << -1;
		return 0;
	}

	/*
	9 8 6
	7 5 4 2 2
	*/

	int ans = 0;
	int cnt = 0;
	while (cnt < M)
	{
		for (int i = 0; i < N; i++)
		{
			int& current = idx[i];
			bool bPossible = true;
			if (current >= M) continue;

			while (checked[current] || boxes[current] > cranes[i])
			{
				current++;
				if (M <= current)
				{
					bPossible = false;
					break;
				}
			}

			if (bPossible)
			{
				cnt++;
				checked[current] = true;
			}
		}

		ans++;
	}

	cout << ans;

	return 0;
}