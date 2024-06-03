#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N;

int CalcDist(pair<int, int>& a, pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<pair<int, int>> CheckPoints;
    vector<pair<int,int>> Dist;

    int total = 0;

    for (int i = 0; i < N; i++)
    {
        int y, x;

        cin >> y >> x;
        CheckPoints.push_back({ y,x });
        if (i == 0) continue;

        total += abs(CheckPoints[i - 1].first - y) + abs(CheckPoints[i - 1].second - x);
    }

    pair<int, int> prev, cur, next;

    int skip = 0;
    for (int i = 1; i < N - 1; i++) {
        prev = CheckPoints[i - 1];
        cur = CheckPoints[i];
        next = CheckPoints[i + 1];
        int dist = CalcDist(prev, cur) + CalcDist(cur, next);
        int straight = CalcDist(prev, next);
        skip = max(skip, dist - straight);
    }

    cout << total - skip;

	return 0;
}