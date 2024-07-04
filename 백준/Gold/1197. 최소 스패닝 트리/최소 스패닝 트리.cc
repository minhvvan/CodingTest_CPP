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

int V,E;
vector<int> link;

bool cmp (tuple<int,int,int>& a, tuple<int, int, int>& b)
{
    return get<2>(a) < get<2>(b);
}

int find(int x)
{
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a > b) swap(a, b);
    link[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    cin >> V >> E;
    
    link.resize(V+1);
    for (int i = 1; i <= V; i++) 
    {
        link[i] = i;
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({ a,b,c });
    }

    sort(edges.begin(), edges.end(), cmp);

    for (auto [a, b, c] : edges)
    {
        if (!same(a, b))
        {
            ans += c;
            unite(a, b);
        }
    }

    cout << ans;

    return 0;
}