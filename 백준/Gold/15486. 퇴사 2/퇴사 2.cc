#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    vector<pair<int, int>> Tasks(1);
    vector<int> income(N+1, 0);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        Tasks.push_back({ a,b });
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        income[i] = max(income[i], income[i - 1]);
        int deadline = i + Tasks[i].first - 1;
        if (deadline > N) continue;

        income[deadline] = max(income[deadline], income[i - 1] + Tasks[i].second);
        ans = max(ans, income[deadline]);
    }

    cout << ans;

    return 0;
}