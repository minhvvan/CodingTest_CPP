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

int T;
string paper;

bool Check(int left, int right)
{
    if (left >= right)
    {
        return true;
    }

    int l = left, r = right;
    while (l < r)
    {
        if (paper[l] != paper[r])
        {
            l++, r--;
        }
        else
        {
            return false;
        }
    }

    return Check(left, r - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> T;

    while (T--)
    {
        cin >> paper;

        if(Check(0, paper.length()-1)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}