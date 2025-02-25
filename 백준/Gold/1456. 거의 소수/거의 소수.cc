#include <bits/stdc++.h>

using namespace std;

long long A, B;
const long long MAX = 10000001;
vector<bool> IsPrime(MAX, true);

void CalcPrime()
{
	for (int i = 2; i * i <= MAX; i++) 
	{
		if (IsPrime[i]) 
		{
			for (int j = i * i; j < MAX; j += i) 
			{
				IsPrime[j] = false;
			}
		}
	}
}

long long GetAlmostPrime()
{
	long long result = 0;

	for (int i = 2; i <= MAX; i++) 
	{
		if (IsPrime[i]) 
		{
			long long num = i, n = 2;
			while (num <= B / i) 
			{ 
				if (A <= num * i) result++;
				num *= i;
			}
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> A >> B;

	CalcPrime();
	cout << GetAlmostPrime();
	
	return 0;
}