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
    vector<int> last(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int len = 0;
    for (int i = 0; i < N; i++)
    {
        int pos = lower_bound(last.begin(), last.begin() + len, nums[i]) - last.begin();

        last[pos] = nums[i];
        if (pos + 1 > len) len++;
    }

    cout << len;

    return 0;
}