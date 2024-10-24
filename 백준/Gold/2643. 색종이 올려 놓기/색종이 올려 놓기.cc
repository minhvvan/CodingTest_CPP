#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> papers;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;
    dp.resize(N, 0);

    //{min, max}
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        papers.push_back({ min(a,b),max(a,b) });
    }

    sort(papers.begin(), papers.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        auto [minLen, maxLen] = papers[i];

        for (int j = 0; j < i; j++)
        {
            auto [currentMin, currentMax] = papers[j];

            if (currentMin <= minLen && currentMax <= maxLen)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}