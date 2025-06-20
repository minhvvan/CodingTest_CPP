#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
const int MAX = 1000000;
vector<bool> isPrime(MAX+1, true);

int main()
{
	INPUT_OPTIMIZE;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (!isPrime[i]) continue;

		for (int j = 2; i * j <= MAX; j++)
		{
			isPrime[i * j] = false;
		}
	}


	while (cin >> N)
	{
		if (N == 0) break;

		bool isPossible = false;
		for (int i = 3; i <= N / 2; i++)
		{
			if (!isPrime[i]) continue;

			if (isPrime[N - i])
			{
				isPossible = true;
				cout << N << " = " << i << " + " << N - i << "\n";
				break;
			}
		}

		if (!isPossible) cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}