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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> Tops(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Tops[i];
    }

    //num, idx
    vector<pair<int, int>> ans(N, {-1, -1});
    for (int i = 1; i < N; i++)
    {
        int prev = Tops[i - 1];
        int current = Tops[i];
        if (prev > current)
        {
            ans[i] = { prev, i - 1 };
            continue;
        }

        int idx = i - 1;
        while (true)
        {
            auto [prevMax, prevIdx] = ans[idx];
            if (prevIdx == -1)
            {
                ans[i] = { -1, -1 };
                break;
            }

            if (prevMax > current)
            {
                ans[i] = { prevMax, prevIdx };
                break;
            }

            idx = prevIdx;
        }
    }

    for (auto [num, idx] : ans)
    {
        cout << idx + 1 << " ";
    }

    return 0;
}