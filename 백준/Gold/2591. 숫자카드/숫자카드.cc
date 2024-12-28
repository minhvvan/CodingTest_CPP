#include <bits/stdc++.h>

using namespace std;

string num;

int ans = 0;

void DFS(int idx)
{
    if (idx == num.length())
    {
        ans++;
        return;
    }

    //1자리
    {
        int n = num[idx] - '0';
        if (n != 0)
        {
            DFS(idx + 1);
        }
    }

    //2자리
    {
        if (idx + 1 >= num.length()) return;

        int n = num[idx] - '0';
        n *= 10;
        n += num[idx + 1] - '0';

        if (10 <= n && n <= 34)
        {
            DFS(idx + 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> num;
    DFS(0);

    cout << ans;

    return 0;
}