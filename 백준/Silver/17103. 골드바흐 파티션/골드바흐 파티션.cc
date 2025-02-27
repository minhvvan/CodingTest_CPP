#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
const int MAX = 1'000'000;
vector<bool> isPrime(MAX+1, true);

void CheckPrime()
{
	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	CheckPrime();

	for (int i = 0; i < N; i++)
	{
		int num = nums[i];

		int ans = 0;
		for (int a = num / 2; a >= 2; a--)
		{
			int b = num - a;
			if (isPrime[a] && isPrime[b]) ans++;
		}

		cout << ans << "\n";
	}
	

	return 0;
}