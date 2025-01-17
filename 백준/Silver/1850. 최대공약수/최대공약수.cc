#include <bits/stdc++.h>

using namespace std;

long long N, M;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	long long g = gcd(N, M);
	
	string ans;
	for (int i = 0; i < g; i++)
	{
		ans += '1';
	}

	cout << ans;

	return 0;
}