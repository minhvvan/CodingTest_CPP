#include <bits/stdc++.h>

using namespace std;

long long N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N >> M;

    vector<long long> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = 1;

    long long ans = LLONG_MAX;
    while (left < N && right < N)
    {
        long long result = nums[right] - nums[left];
        if (result < M)
        {
            right++;
        }
        else
        {
            ans = min(ans, result);
            left++;
        }
    }

    cout << ans;

    return 0;
}