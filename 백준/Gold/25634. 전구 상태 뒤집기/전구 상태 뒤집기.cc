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

    vector<int> scores(N+1);
    vector<int> lights(N+1);

    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> scores[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> lights[i];
    }

    int answer = 0;
    int maxScore = INT_MIN;
    for (int i = 1; i <= N; i++)
    {
        if (lights[i] == 1)
        {
            answer += scores[i];
            dp[i] = max(dp[i - 1] - scores[i], -scores[i]);
        }
        else
        {
            dp[i] = max(dp[i - 1] + scores[i], scores[i]);
        }

        maxScore = max(maxScore, dp[i]);
    }

    cout << answer + maxScore << '\n';

    return 0;
}