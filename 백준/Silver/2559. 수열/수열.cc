#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> K;

    vector<int> temperature(N);
    vector<int> sum(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> temperature[i];
        if (i == 0) sum[i] = temperature[i];
        else sum[i] = sum[i - 1] + temperature[i];
    }

    int ans = sum[K-1];
    for (int i = 1; i + K - 1 < N; i++)
    {
        ans = max(ans, sum[i + K - 1] - sum[i - 1]);
    }

    cout << ans;

    return 0;
}