#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
 long long N, t = 1;
const long long MOD = 1e12;

void f()
{
	while (t % 10 == 0) 
	{
		t /= 10;
	}
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 1; i <= N; ++i) 
	{
		t *= i;
		f();
		t %= MOD;
	}

	printf("%05lld", t % 100000);

	return 0;
}