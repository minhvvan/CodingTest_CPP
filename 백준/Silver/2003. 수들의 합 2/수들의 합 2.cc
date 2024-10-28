#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> M;

    int ans = 0;

    vector<int> nums(N+1);
    vector<int> sumStack(N+1,0);
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        sumStack[i] = sumStack[i - 1] + nums[i];
    }

    int left = 0;
    int right = 0;

    while (left <= N && right <= N && left <= right)
    {
        int sum = sumStack[right] - sumStack[left];
        if (sum == M)
        {
            ans++;
            right++;
        }
        else if (sum < M) right++;
        else left++;
    }

    cout << ans;

    return 0;
}