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

    priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    vector<set<string>> ans(101);
    map<string, int> minRank;
    int maxRank = 0;

    for (int i = 0; i < N; i++)
    {
        int a, b;

        cin >> a;
        cin.ignore(4);
        cin >> b;
        maxRank = max(maxRank, b);

        for (int j = 0; j < a; j++)
        {
            string song;
            cin >> song;

            pq.push({ b, song });
        }
    }

    while (!pq.empty())
    {
        auto [rank, name] = pq.top();
        pq.pop();

        if (minRank.count(name) != 0 && minRank[name] <= rank) continue;

        ans[rank].insert(name);
        minRank[name] = rank;
    }

    vector<int> sum(maxRank + 1, 0);
    for (int i = 1; i <= maxRank; i++)
    {
        sum[i] = sum[i-1] + ans[i].size();
    }

    for (int i = 1; i <= maxRank; i++)
    {
        if (sum[i - 1] == i - 1 && ans[i].size() == 1)
        {
            cout << i << " " << *ans[i].begin() << "\n";
        }
    }

    return 0;
}