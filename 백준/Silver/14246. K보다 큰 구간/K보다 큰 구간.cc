#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
vector<int> nums;
vector<long long> sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    nums.resize(N+1);
    sum.resize(N+1);

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
    }

    cin >> K;

    sum[1] = nums[1];
    for (int i = 2; i <= N; i++)
    {
        sum[i] = sum[i - 1] + nums[i];
    }

    long long ans = 0;

    int left = 0, right = 0;
    while (left <= right && right <= N)
    {
        long long s = sum[right] - sum[left];
        if (K < s)
        {
            ans += N - right + 1;
            left++;
        }
        else
        {
            right++;
        }
    }


    cout << ans;

    return 0;
}