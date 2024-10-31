#include <bits/stdc++.h>

using namespace std;

int N, X;

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

    cin >> X;

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = N-1;
    int ans = 0;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == X)
        {
            ans++;
            left++;
        }
        else if(sum > X)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << ans;

    return 0;
}