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

int N;

double GetArea(vector<pair<int, int>>& points)
{
    double result = 0;
    for (int i = 1; i < N - 1; i++) {
        double x1 = points[0].first;
        double y1 = points[0].second;
        
        double x2 = points[i].first;
        double y2 = points[i].second;

        double x3 = points[i + 1].first;
        double y3 = points[i + 1].second;

        double size = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

        result += size / 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    vector<pair<int, int>> points;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        points.push_back({ a,b });
    }

    double answer = GetArea(points);
    cout << fixed;
    cout.precision(1);
    cout << abs(answer) << endl;

    return 0;
}