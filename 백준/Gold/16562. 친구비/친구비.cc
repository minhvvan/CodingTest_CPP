#include <bits/stdc++.h>

using namespace std;

int N, M, k;
vector<int> costs;
vector<int> link;

int find(int x)
{
    if (link[x] == x) return x;
    return link[x] = find(link[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (costs[a] > costs[b]) swap(a, b);
    costs[b] = 0;
    link[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M >> k;

    costs.resize(N+1);
    link.resize(N+1);

    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
        link[i] = i;
    }

    for (int j = 1; j <= M; j++)
    {
        int a, b;
        cin >> a >> b;

        unite(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += costs[i];
    }

    if (ans > k) cout << "Oh no";
    else cout << ans;

    return 0;
}