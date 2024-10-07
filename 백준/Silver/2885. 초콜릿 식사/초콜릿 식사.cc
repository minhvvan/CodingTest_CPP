#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> K;

	int total = 1, ans = 0, cnt = 0, temp = 0;

	while (total < K)
	{
		int i = 1;
		total <<= i;
	}

	temp = total;
	int origin = K;

	for (; K != 0; cnt++) 
	{
		K &= (K - 1);
	}

	int oneCnt = 0;
	while (cnt != oneCnt) 
	{
		if ((origin & temp) != 0)
		{
			oneCnt++;
		}

		ans++;
		temp >>= 1;
	}

	cout << total << ' ' << ans - 1 << '\n';

    return 0;
}