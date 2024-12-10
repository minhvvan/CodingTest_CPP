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

    if (N < 10)
    {
        cout << N;
        return 0;
    }

    vector<int> digit;
    while (N > 0)
    {
        digit.push_back(N % 10);
        N /= 10;
    }

    for (int i = 0; i < digit.size()-1; i++)
    {
        if (digit[i] >= 5) digit[i + 1]++;
        digit[i] = 0;
    }

    reverse(digit.begin(), digit.end());

    int ans = 0;
    for (auto d : digit)
    {
        ans *= 10;
        ans += d;
    }

    cout << ans;

    return 0;
}