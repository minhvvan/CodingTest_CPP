#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> K;

    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;
    int left = 0;
    int right = 0;
    int oddCnt = 0;
    int evenCnt = 0;

    while (right < N)
    {
        if (oddCnt <= K)
        {
            if (nums[right] & 1)
            {
                oddCnt++;
            }
            else
            {
                evenCnt++;
                ans = max(ans, evenCnt);
            }

            right++;
        }
        else
        {
            if (nums[left] & 1)
            {
                oddCnt--;
            }
            else
            {
                evenCnt--;
            }

            left++;
        }
    }

    cout << ans;

    return 0;
}