#include <bits/stdc++.h>

using namespace std;

long long A, B, C;

long long power(long long b)
{
	if (b == 0) return 1;
	if (b == 1) return A % C;

	long long temp = power(b / 2) % C;
	if (b % 2 == 0) return temp * temp % C;
	return temp * temp % C * A % C;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> A >> B >> C;

	cout << power(B);

	return 0;
}