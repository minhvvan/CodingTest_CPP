#include <bits/stdc++.h>

using namespace std;

long long N, M;

long long GetCnt(long long num, long long div)
{
	long long cnt = 0;

	for (long long i = div; i <= num; i *= div)
	{
		cnt += num / i;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;

	auto c2 = GetCnt(N, 2) - GetCnt(N - M, 2) - GetCnt(M, 2);
	auto c5 = GetCnt(N, 5) - GetCnt(N - M, 5) - GetCnt(M, 5);

	cout << min(c2, c5);

	return 0;
}