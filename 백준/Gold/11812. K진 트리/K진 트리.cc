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

    for (int i = 0; i < Q; ++i)
    {
        long long a, b;
        cin >> a >> b;
        long long count = 0;
        if (K == 1)
        {
            count = abs(a - b);
        }
        else
        {
            while (a != b)
            {
                if (a > b)
                {
                    a = (a - 2) / K + 1;
                }
                else
                {
                    b = (b - 2) / K + 1;
                }

                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}