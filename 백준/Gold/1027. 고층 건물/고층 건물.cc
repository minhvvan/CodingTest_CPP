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
vector<long long> buildings;

bool check(int start, int end)
{
    if (end < start) swap(start, end);
    double slope = double(buildings[end] - buildings[start]) / (end - start);

    for (int i = start + 1; i < end; i++)
    {
        double value = slope * (i - start) + buildings[start];
        if (buildings[i] >= value) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    buildings.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> buildings[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int current = 0;

        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            if (check(i, j)) current++;
        }

        ans = max(ans, current);
    }

    cout << ans;

    return 0;
}