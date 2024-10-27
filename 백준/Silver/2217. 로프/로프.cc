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

    vector<int> ropes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end());

    int ans = ropes.back();
    int cnt = 2;
    for (int i = N - 2; i >= 0; i--)
    {
        int temp = ropes[i] * cnt++;
        ans = max(ans, temp);
    }

    cout << ans;

    return 0;
}