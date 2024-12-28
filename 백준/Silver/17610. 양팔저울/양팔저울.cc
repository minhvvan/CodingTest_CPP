#include <bits/stdc++.h>

using namespace std;

int N, S = 0;
vector<int> weights;
vector<bool> possible;

void DFS(int idx, int total)
{
    possible[total] = true;

    if (idx == N)
    {
        return;
    }

    int current = weights[idx];
    possible[current] = true;

    DFS(idx + 1, total);
    DFS(idx + 1, total+current);
    DFS(idx + 1, abs(total - current));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    weights.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
        S += weights[i];
    }

    possible.resize(S+1, false);

    DFS(0, 0);

    int ans = 0;
    for (int i = 1; i <= S; i++)
    {
        if (!possible[i]) ans++;
    }

    cout << ans;

    return 0;
}