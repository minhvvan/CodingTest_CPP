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

    vector<long long> A;
    vector<long long> B;
    vector<long long> C;
    vector<long long> D;

    for (int i = 0; i < N; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    vector<long long> AB;
    vector<long long> CD;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long ans = 0;
    for (int i = 0; i < AB.size(); i++)
    {
        auto under = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        auto over = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();

        ans += (over - under);
    }

    cout << ans;

    return 0;
}