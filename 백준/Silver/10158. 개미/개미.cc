#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

int main()
{
	INPUT_OPTIMIZE;
	
    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    if ((p + t) / w % 2 == 0) 
    {
        cout << (p + t) % w << ' ';
    }
    else cout << w - (p + t) % w << ' ';

    if ((q + t) / h % 2 == 0) 
    {
        cout << (q + t) % h;
    }
    else cout << h - (q + t) % h;

	return 0;
}