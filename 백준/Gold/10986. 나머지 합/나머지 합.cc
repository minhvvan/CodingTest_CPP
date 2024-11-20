#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    vector<long long> cnt(M+1);
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        cnt[sum % M]++;
    }

    long long ans = 0;
    for (int i = 0; i <= M; i++)
    {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans+cnt[0];

    return 0;
}