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

int N, C;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    vector<pair<int, int>> farms;
    vector<bool> visited(N, false);
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int y, x;
        cin >> y >> x;
        farms.push_back({ y,x });
    }

    //MST
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,0 });

    while (!pq.empty())
    {
        auto [dist, idx] = pq.top();
        pq.pop();

        if (visited[idx]) continue;
        visited[idx] = true;

        dist *= -1;
        answer += dist;

        for (int i = 0; i < N; i++)
        {
            if (i == idx) continue;

            int d = (farms[i].first - farms[idx].first) * (farms[i].first - farms[idx].first) + (farms[i].second - farms[idx].second) * (farms[i].second - farms[idx].second);
            if (d < C) continue;

            pq.push({ -d, i });
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            cout << -1;
            return 0;
        }
    }

    if (answer == 0) cout << -1;
    else cout << answer;
    

	return 0;
}