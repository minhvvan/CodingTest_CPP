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

    int left = 1;
    int right = 1;

    int sum = 1;
    int ans = 0;
    while (right <= N)
    {
        if (sum == N)
        {
            ans++;
            sum -= left;
            left++;
        }
        else if (sum > N)
        {
            sum -= left;
            left++;
        }
        else
        {
            right++;
            sum += right;
        }
    }

    cout << ans;

    return 0;
}