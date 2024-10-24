#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    int ans = 0;
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        vector<int> nums;
        nums.push_back(N);
        nums.push_back(i);

        while (nums[nums.size()-2] - nums[nums.size()-1] >= 0)
        {
            int newNum = nums[nums.size() - 2] - nums[nums.size() - 1];
            nums.push_back(newNum);
        }

        if (ans < nums.size())
        {
            ans = nums.size();
            arr = nums;
        }
    }

    cout << ans << "\n";
    for (auto num : arr)
    {
        cout << num << " ";
    }

    return 0;
}