#include <bits/stdc++.h>

using namespace std;

int T, N, M;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        if (N == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<pair<int, int>> students;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            students.push_back({ a,b });
        }

        sort(students.begin(), students.end(), cmp);

        vector<bool> checked(N + 1, false);
        int ans = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = students[i].first; j <= students[i].second; j++)
            {
                if (!checked[j])
                {
                    ans++;
                    checked[j] = true;
                    break;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}