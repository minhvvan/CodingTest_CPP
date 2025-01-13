#include <bits/stdc++.h>

using namespace std;

int N;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	for (int i = 1; i <= N; ++i) 
	{
		ans += (N / i) * i;
	}

	cout << ans;

	return 0;
}