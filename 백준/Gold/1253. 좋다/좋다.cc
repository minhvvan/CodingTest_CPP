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

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int target = nums[i];
        int left = 0;
        int right = N - 1;

        if (left == i) left++;
        if (right == i) right--;

        while (left < right)
        {
            long long sum = nums[left] + nums[right];

            if (sum == target)
            {
                ans++;
                break;
            }
            else if (sum < target)
            {
                left++;
                if (left == i) left++;
            }
            else
            {
                right--;
                if (right == i) right--;
            }
        }
    }

    cout << ans;

    return 0;
}