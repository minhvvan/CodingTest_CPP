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

using namespace std;

long long N, K, Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> Q;

    for (int i = 0; i < Q; ++i) {
        long long int y, x;
        cin >> y >> x;
        long long int count = 0;
        if (K == 1) {
            count = abs(y - x);
        }
        else {
            while (y != x) {
                if (y > x) {
                    y = (y - 2) / K + 1;
                }
                else {
                    x = (x - 2) / K + 1;
                }
                ++count;
            }
        }
        cout << count << '\n';
    }

    return 0;
}