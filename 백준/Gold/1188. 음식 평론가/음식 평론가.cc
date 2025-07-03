#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;

int GCD(int a, int b)
{
	if (b == 0) return a;
	if (a < b) swap(a, b);
	return GCD(b, a % b);
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;
	cout << M - GCD(N, M);

	return 0;
}