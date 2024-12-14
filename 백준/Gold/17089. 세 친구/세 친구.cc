#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = INT_MAX;
vector<vector<int>> friends;
vector<vector<bool>> isFriend;

void dfs(int start, int x, int sum, vector<int>& temp)
{
    if (temp.size() == 3)
    {
        if (!isFriend[start][x]) return;
        ans = min(sum - 6, ans);
        return;
    }


    for (auto next : friends[x])
    {
        if (lower_bound(temp.begin(), temp.end(), next) != temp.end()) continue;
        temp.push_back(next);
        dfs(next, start, sum + friends[next].size(), temp);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    friends.resize(N+1);
    isFriend.resize(N+1, vector<bool>(N+1, false));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        isFriend[a][b] = true;
        isFriend[b][a] = true;
    }

    vector<int> temp;
    for (int i = 1; i <= N; i++)
    {
        temp.push_back(i);
        dfs(i, i, friends[i].size(), temp);
        temp.pop_back();
    }

    if (ans == INT_MAX) ans = -1;
    cout << ans;

    return 0;
}