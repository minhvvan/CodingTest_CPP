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

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

	vector<int> neg, pos;

    cin >> N >> M;
	while (N--) 
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			pos.push_back(num);
		}
		else 
		{
			num = (-num);
			neg.push_back(num);
		}
	}

	int ans = 0;
	
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());

	for (int i = neg.size() - 1; i >= 0; i -= M)
	{
		ans += neg[i] * 2;
	}

	for (int i = pos.size() - 1; i >= 0; i -= M)
	{
		ans += pos[i] * 2;
	}

	if (!neg.empty() && !pos.empty())
	{
		if (neg.back() < pos.back())
		{
			ans -= pos.back();
		}
		else
		{
			ans -= neg.back();
		}
	}
	else if(neg.empty())
	{
		ans -= pos.back();
	}
	else
	{
		ans -= neg.back();
	}
	
	cout << ans;

    return 0;
}