#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        X.push_back({ a,b });
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Y.push_back({ a,b });
    }

    int a, b;
    cin >> a >> b;

    long long ans = 0;
    set<int> checked;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int shift = Y[j].first - X[i].first;
            if (a > shift || b < shift) continue;
            if (checked.count(shift)) continue;
            checked.insert(shift);

            int xIdx = 0;
            int yIdx = 0;

            while (xIdx < N && yIdx < M)
            {
                int x = X[xIdx].first;
                int y = Y[yIdx].first;

                if (shift < 0) x += shift;
                else y -= shift;

                if (x == y) ans += X[xIdx++].second * Y[yIdx++].second;
                else if (x < y) xIdx++;
                else yIdx++;
            }
        }
    }

    cout << ans;

    return 0;
}