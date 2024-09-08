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

long long X, Y, W, S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y >> W >> S;
    long long case_A = (X + Y) * W;
    long long case_B = min(X, Y) * S;
    case_B += min(abs(X - Y) * W, (abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W : abs(X - Y) * S));

    cout << min(case_A, case_B);

    return 0;
}