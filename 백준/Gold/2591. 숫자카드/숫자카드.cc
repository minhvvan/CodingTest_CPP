#include <bits/stdc++.h>

using namespace std;

string num;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> num;
    dp.resize(num.length());

    dp[0] = 1;
    for (int i = 1; i < num.length(); i++)
    {
        if (i > 0 && num[i] != '0') dp[i] += dp[i - 1];

        int n = stoi(num.substr(i-1, 2));

        if (10 <= n && n <= 34) 
        {
            dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
        }
    }

    cout << dp[num.length() - 1];

    return 0;
}