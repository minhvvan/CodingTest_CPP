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
    vector<pair<int, int>> skyline;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        skyline.push_back({ x,y });
    }

    int ans = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        if (visited[i]) continue;
        for (int j = i+1; j < N; j++)
        {
            if (skyline[i].second <= skyline[j].second)
            {
                if(skyline[i].second == skyline[j].second) visited[j] = true;
                continue;
            }

            break;
        }

        if(skyline[i].second != 0) ans++;
    }

    cout << ans;
    return 0;
}