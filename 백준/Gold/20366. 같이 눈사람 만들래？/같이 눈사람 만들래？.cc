#include <bits/stdc++.h>

using namespace std;

int N;
int ans = INT_MAX;

vector<int> nums;

int getTall(int bottom, int top)
{
    return nums[bottom] + nums[top];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N;
    nums.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int left = i + 1;
            int right = j - 1;

            int e = getTall(i, j);
            while (left < right)
            {
                int a = getTall(left, right);

                ans = min(ans, abs(e - a));
                if (e < a)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}