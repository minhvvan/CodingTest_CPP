#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<int> root;

int findRoot(int x)
{
    if (root[x] == x) return x;
    return root[x] = findRoot(root[x]);
}

void Union(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);

    //빠른 순서 정렬
    if (a > b) swap(a, b);
    root[b] = a;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    root.resize(N+1);
    for (int i = 1; i <= N; i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (findRoot(i) == i) ans++;
    }

    cout << ans;

    return 0;
} 