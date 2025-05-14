#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> tree;

void dfs(int start, int cost)
{
    for (auto [next, c] : adj[start])
    {
        if (tree[next].first != 0) continue;

        tree[next] = { start, cost + c };
        dfs(next, cost + c);
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    adj.resize(N + 1);
    tree.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    //루트는 1
    tree[1] = { 1, 0 };
    dfs(1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        //depth와 누적 cost를 구했으니
        //부모가 같을때까지 올린다
        //부모가 같은 부분에서의 cost를 c라고 한다면
        //(a-c) + (b-c)

        int left = a;
        int right = b;
        unordered_set<int> leftPath;
        unordered_set<int> rightPath;

        leftPath.insert(left);
        rightPath.insert(right);

        while (left != right)
        {
            left = tree[left].first;
            right = tree[right].first;

            if (left == right)
            {
                cout << (tree[a].second - tree[left].second) + (tree[b].second - tree[right].second) << "\n";
                break;
            }

            if (rightPath.count(left) > 0)
            {
                cout << (tree[a].second - tree[left].second) + (tree[b].second - tree[left].second) << "\n";
                break;
            }

            if (leftPath.count(right) > 0)
            {
                cout << (tree[a].second - tree[right].second) + (tree[b].second - tree[right].second) << "\n";
                break;
            }

            if(left != 1) leftPath.insert(left);
            if(right != 1) rightPath.insert(right);
        }
    }

    return 0;
} 