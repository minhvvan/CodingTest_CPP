#include <bits/stdc++.h>

using namespace std;

int N;

bool CheckPre(string& pre, string& target)
{
    bool flag = true;
    for (int i = 0; i < pre.length(); i++)
    {
        if (pre[i] != target[i])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> N;

    vector<string> words(N);
    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    sort(words.begin(), words.end());

    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        /*
                    h hello hi rerun run running
            h       0 1     1   2   2   2
            hello   0 0     2   2   2   2 
            hi      0 0     0   3   3   3
            rerun   0 0     0   0   4   4
            run     0 0     0   0   0   4
            running 0 0     0   0   0   0
        */

        for (int j = i+1; j < N; j++)
        {
            if (!CheckPre(words[i], words[j]))
            {
                dp[j] = dp[i] + 1;
            }

            ans = max(ans, dp[j]);
        }
    }

    cout << ans;

    return 0;
}