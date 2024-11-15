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

    vector<int> nums(N);
    vector<int> last(N);
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int len = 1;
    last[0] = nums[0];
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        int pos = lower_bound(last.begin(), last.begin() + len, nums[i]) - last.begin();
        dp[i] = pos+1;

        last[pos] = nums[i];
        if (dp[i] > len) len++;
    }

    cout << len;

    return 0;
}