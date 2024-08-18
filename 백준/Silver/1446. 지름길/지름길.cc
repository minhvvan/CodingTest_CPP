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

int N, D;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;

    vector<vector<pair<int, int>>> shortcuts(D+1);

    for (int i = 0; i < N; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;

        shortcuts[start].push_back({ end, cost });
    }

    vector<int> distance(D+1);
    for (int i = 0; i < D+1; i++) distance[i] = i;
    vector<bool> visited(D+1, false);

    for (int i = 0; i <= D; i++)
    {
        if (i != 0) 
        { 
            distance[i] = min(distance[i], distance[i - 1] + 1);
        }

        for (auto [end, cost] : shortcuts[i])
        {
            if (end > D) continue;
            distance[end] = min(distance[end], distance[i] + cost);
        }
    }

    cout << distance[D];

    return 0;
}