#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long X, Y, Z;

int main()
{
	INPUT_OPTIMIZE;

	cin >> X >> Y;

	Z = Y * 100 / X;

	if (Z >= 99) {
		cout << -1;
		return 0;
	}

	int left = 0, right = 1000000000;

	while (left <= right) 
	{
		int mid = (left + right) / 2;
		int temp = (Y + mid) * 100 / (X + mid);

		if (Z < temp) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;

	return 0;
}