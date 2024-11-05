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

    //x^2 - y^2 = N
    int left = 1;
    int right = 2;

    bool bExist = false;
    while (left < right)
    {
        int g = right * right - left * left;

        if (g == N)
        {
            cout << right << "\n";
            bExist = true;
        }

        if (g > N)
        {
            left++;
        }
        else
        {
            right++;
        }
    }

    if (!bExist) cout << -1;

    return 0;
}