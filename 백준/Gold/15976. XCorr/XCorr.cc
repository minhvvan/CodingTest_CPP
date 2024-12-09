#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> XIdx;
vector<int> X;
vector<int> YIdx;
vector<int> Y;
vector<long long> sums;

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
        XIdx.push_back(a);
        X.push_back(b);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        YIdx.push_back(a);
        Y.push_back(b);
    }

    int a, b;
    cin >> a >> b;

    sums.push_back(0);
    for (int i = 0; i < M; i++) 
    {
        sums.push_back(sums[i] + Y[i]);
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) 
    {
        int s = lower_bound(YIdx.begin(), YIdx.end(), XIdx[i] + a) - YIdx.begin();
        int e = upper_bound(YIdx.begin(), YIdx.end(), XIdx[i] + b) - YIdx.begin();
        ans += X[i] * (sums[e] - sums[s]);
    }

    cout << ans;

    return 0;
}