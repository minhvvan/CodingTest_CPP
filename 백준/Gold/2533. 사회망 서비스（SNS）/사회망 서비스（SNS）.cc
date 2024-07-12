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
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> visited;

void find(int x)
{
    dp[x][1] = 1;

    for (auto next : adj[x])
    {
        if (visited[next]) continue;
        visited[x] = true;

        find(next);
        dp[x][0] += dp[next][1];
        dp[x][1] += min(dp[next][0], dp[next][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    cin >> N;

    adj.assign(N + 1, vector<int>());
    dp.assign(N + 1, vector<int>(2, 0));
    visited.assign(N + 1, false);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find(1);

    int ans = dp[1][0] > dp[1][1] ? dp[1][1] : dp[1][0];
    cout << ans;

    return 0;
}