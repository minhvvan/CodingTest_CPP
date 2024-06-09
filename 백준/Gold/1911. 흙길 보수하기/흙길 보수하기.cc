#include <stdio.h>
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

int N, L;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    vector<pair<int, int>> Pools;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;

        Pools.push_back({ start, end });
    }

    sort(Pools.begin(), Pools.end());

    int next = 0;
    for (int i = 0; i < Pools.size(); ++i) 
    {
        if (next < Pools[i].first) next = Pools[i].first;

        while (next < Pools[i].second) 
        {
            next += L;
            answer++;
        }
    }

    cout << answer;

    return 0;
}