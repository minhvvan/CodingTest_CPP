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

string S, P;

bool IsSubstr(const string& str)
{
    auto result = S.find(str);
    return result != string::npos;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> S >> P;

    int ans = 0;
    for (int i = P.length() - 1; i >= 0; i--)
    {
        string str;
        str += P[i];

        int offset = 0;
        while (IsSubstr(str))
        {
            offset++;
            if (i - offset < 0) break;
            str = P[i - offset] + str;
        }
        offset--;

        i -= offset;
        ans++;
    }

    cout << ans;

    return 0;
}