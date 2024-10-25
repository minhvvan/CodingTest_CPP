#include <bits/stdc++.h>

using namespace std;

float N, M;
vector<int> dp;
vector<int> vip;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N >> M;

    dp.resize(N+1);
    vip.resize(M+1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    long long ans = 1;
    for (int i = 1; i <= M; i++)
    {
        cin >> vip[i];
    }

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int start = 0;
    for (int i = 1; i <= M; i++)
    {
        int end = vip[i];

        ans *= dp[end - start - 1];
        start = end;
    }

    ans *= dp[N - start];
    cout << ans;

    return 0;
}