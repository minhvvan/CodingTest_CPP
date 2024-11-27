#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> digCosts;
vector<vector<int>> dragCosts;
vector<vector<long long>> dp;

long long bfs(int start, vector<long long>& costs)
{
    costs[start] = 0;

    priority_queue<pair<long long, int>> pq;
    vector<bool> visited(N, false);
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto [cost, current] = pq.top();
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (int i = 0; i < N; i++)
        {
            if (i == current) continue;
            if (visited[i]) continue;

            int dist = min(digCosts[i], dragCosts[current][i]);
            if (dist < costs[i])
            {
                costs[i] = dist;
                pq.push({-dist, i});
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        result += costs[i];
    }

    return result + digCosts[start];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    digCosts.resize(N);
    dragCosts.resize(N, vector<int>(N));
    dp.resize(N, vector<long long>(N, LLONG_MAX));

    for (int i = 0; i < N; i++)
    {
        cin >> digCosts[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> dragCosts[i][j];
        }
    }

    //i번이 시작일 때
    long long ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        ans = min(ans, bfs(i, dp[i]));
    }

    cout << ans;

    return 0;
}