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
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    vector<pair<int, int>> columns;
    int maxHeight = 0;
    int maxLoc = 0;

    for (int i = 0; i < N; i++)
    {
        int loc, height;
        cin >> loc >> height;

        columns.push_back({ loc, height });
        if (maxHeight < height)
        {
            maxHeight = height;
            maxLoc = loc;
        }
    }

    sort(columns.begin(), columns.end());

    int ans = maxHeight;
    {
        int currentHeight = columns.begin()->second;
        int prevLoc = columns.begin()->first;

        for (auto itr = ++columns.begin(); itr != columns.end() && itr->first <= maxLoc; itr++)
        {
            int loc = itr->first;
            int height = itr->second;

            ans += currentHeight * (loc - prevLoc);

            currentHeight = max(currentHeight, height);
            prevLoc = loc;
        }
    }

    {
        int currentHeight = columns.rbegin()->second;
        int prevLoc = columns.rbegin()->first;

        for (auto itr = ++columns.rbegin(); itr != columns.rend() && itr->first >= maxLoc; itr++)
        {
            int loc = itr->first;
            int height = itr->second;

            ans += currentHeight * (prevLoc - loc);

            currentHeight = max(currentHeight, itr->second);
            prevLoc = loc;
        }
    }

    cout << ans;

    return 0;
}