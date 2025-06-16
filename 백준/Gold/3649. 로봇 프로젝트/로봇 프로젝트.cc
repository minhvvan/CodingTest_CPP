#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long hole;
int N;

int main()
{
	INPUT_OPTIMIZE;

	while (cin >> hole)
	{
		cin >> N;
		vector<int> blocks(N);

		for (int i = 0; i < N; i++)
		{
			cin >> blocks[i];
		}

		hole *= 10'000'000;

		sort(blocks.begin(), blocks.end());

		int maxDiff = -1;
		int left = N, right = N;
		for (int i = 0; i < N; i++)
		{
			auto pos = lower_bound(blocks.begin() + i + 1, blocks.end(), hole - blocks[i]) - blocks.begin();

			if (pos < N && blocks[pos] == hole - blocks[i])
			{
				if (blocks[pos] - blocks[i] > maxDiff)
				{
					maxDiff = blocks[pos] - blocks[i];
					left = i;
					right = pos;
				}
			}
		}

		if (left == N && right == N)
		{
			cout << "danger\n";
		}
		else
		{
			cout << "yes " << blocks[left] << " " << blocks[right] << "\n";
		}
	}

	return 0;
}