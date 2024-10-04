#include <iostream>
#include <string.h>

using namespace std;

int N, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> a >> b;

	a--;
	b--;

	int ans = 1;
	while (a / 2 != b / 2)
	{
		ans++;
		a /= 2;
		b /= 2;
	}

	cout << ans;
	return 0;
}