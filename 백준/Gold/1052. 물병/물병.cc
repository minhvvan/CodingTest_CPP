#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

int main() 
{
    INPUT_OPTIMIZE;

	int n, k;
	cin >> n >> k;

	if (k >= n) 
	{
		cout << 0;
	}
	else 
	{
		int answer = 0;

		while (1) 
		{
			bitset<30> num(n);
			if (num.count() <= k) break;

			n++;
			answer++;
		}

		cout << answer;
	}

    return 0;
} 