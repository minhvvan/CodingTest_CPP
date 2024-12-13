#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 987'654'321;
vector<vector<int>> dp;
set<int> blockDays;

int solve(int now, int coup)
{
    if (now > N) return 0;

    int& ret = dp[now][coup];
    if (ret != 0) return ret;

    ret = MAX;
    if (blockDays.count(now) == 0) 
    {
        if (coup >= 3) ret = min(ret, solve(now + 1, coup - 3));

        // 하루권
        ret = min(ret, solve(now + 1, coup) + 10000);

        // 3일권
        ret = min(ret, solve(now + 3, coup + 1) + 25000);

        // 5일권
        ret = min(ret, solve(now + 5, coup + 2) + 37000);
    }
    else 
    {
        ret = min(ret, solve(now + 1, coup));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    if (M != 0)
    {
        for (int i = 0; i < M; i++)
        {
            int d;
            cin >> d;
            blockDays.insert(d);
        }
    }

    dp.resize(N+1, vector<int>(303));
    cout << solve(1, 0);

    return 0;
}