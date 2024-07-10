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

int CCW(vector<pair<int, int>>& points)
{
    int x1 = points[0].first;
    int y1 = points[0].second;

    int x2 = points[1].first;
    int y2 = points[1].second;

    int x3 = points[2].first;
    int y3 = points[2].second;


    //return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> points;

    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;

        points.push_back({ a,b });
    }

    int z = CCW(points);
    if (z == 0) cout << 0;
    else if (z < 0) cout << -1;
    else cout << 1;

    return 0;
}