#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    vector<vector<int>> rect(101, vector<int>(101, 0));

    int ans = 0;
    for (int t = 0; t < 4; t++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        for (int i = a; i < c; i++)
        {
            for (int j = b; j < d; j++)
            {
                if (rect[i][j] == 0)
                {
                    ans++;
                    rect[i][j] = 1;
                }
            }
        }
    }

    cout << ans;

    return 0;
}