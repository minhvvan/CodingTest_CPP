#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> P;
vector<int> X;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    P.resize(N, 0);
    X.resize(M, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }

    vector<bool> visited(N, false);
    queue<tuple<int, int,int>> q;
    q.push({P[0], 0, 0});
    int currentMax = 0;
    while (!q.empty())
    {
        auto [pos, idx, cnt] = q.front();
        q.pop();

        if (visited[idx]) continue;
        visited[idx] = true;

        int maxDist = pos + X[idx];
        if (maxDist <= currentMax) continue;
        currentMax = maxDist;

        if (M <= maxDist)
        {
            cout << cnt;
            exit(0);
        }

        int nextIdx = upper_bound(P.begin() + idx, P.end(), maxDist) - P.begin();
        nextIdx--;

        for(int i = idx+1; i <= nextIdx; i++)
        {
            if (P[i] < M)
            {
                q.push({ P[i], i, cnt + 1 });
            }
        }
    }

    cout << -1;

    return 0;
}