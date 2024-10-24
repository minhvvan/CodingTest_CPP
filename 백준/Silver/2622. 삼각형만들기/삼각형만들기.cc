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

    for (int i = 1; i <= N / 3; i++)
    {
        int rest = N - i;

        for (int j = i; j <= rest / 2; j++)
        {
            int c = max({ i, j, rest - j });

            if (c < N - c)
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}