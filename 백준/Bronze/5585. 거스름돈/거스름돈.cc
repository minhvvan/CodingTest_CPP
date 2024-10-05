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


//500엔, 100엔, 50엔, 10엔, 5엔, 1엔
int price;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> price;

    int rest = 1'000 - price;

    int ans = 0;
    vector<int> coins = { 500, 100, 50, 10, 5, 1 };
    int idx = 0;

    while (rest != 0)
    {
        if (rest >= coins[idx])
        {
            ans++;
            rest -= coins[idx];
        }
        else
        {
            idx++;
        }
    }

    cout << ans;

    return 0;
}