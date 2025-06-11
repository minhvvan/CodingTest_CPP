#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T;
int M, N, x, y;

int main()
{
	INPUT_OPTIMIZE;

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> x >> y;

        while (true)
        {
            if (x == y)
            {
                cout << x << "\n";
                break;
            }
            else if (x > M * N)
            {
                cout << -1 << "\n";
                break;
            }

            if (x < y)
            {
                x += M;
            }
            else
            {
                y += N;
            }
        }
	}

	return 0;
}