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
#include <set>
#include <list>
#include <bitset>

using namespace std;

string str;
int cnt;

int Count(int idx)
{
	int ret = 0;
	int len = str.length();
	for (int i = idx; i < idx + cnt; i++)
	{
		if (str[i % len] == 'a')
		{
			ret++;
		}
	}

	return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

	cnt = 0;
	int ans = INT_MAX;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')cnt++;
	}

	for (int i = 0; i < str.length(); i++)
	{
		ans = min(ans, Count(i));
	}

	cout << ans;

    return 0;
}