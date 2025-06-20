#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long N;

int main()
{
	INPUT_OPTIMIZE;

    cin >> N;
    if (N & 1) cout << "SK";
    else cout << "CY";

	return 0;
}