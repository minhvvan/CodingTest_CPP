#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1003001;
vector<bool> isPrime(MAX + 1, true);

bool IsPalindrome(int n)
{
	string str = to_string(n);

	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			return false;
		}
	}

	return true;
}

void CheckPrime()
{
	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * 2; j <= MAX; j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	CheckPrime();
	isPrime[1] = false;

	for (int i = N; i <= MAX; i++)
	{
		if (isPrime[i] && IsPalindrome(i))
		{
			cout << i;
			break;
		}
	}

	return 0;
}