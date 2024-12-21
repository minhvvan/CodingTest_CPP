#include <bits/stdc++.h>

using namespace std;

int A, B, N, M;

vector<int> oper = { 1, -1 };

int getNext(int pos, int idx)
{
    if (5 < idx) return pos * oper[idx];
    return pos + oper[idx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> A >> B >> N >> M;

    oper.push_back(A);
    oper.push_back(-A);
    oper.push_back(B);
    oper.push_back(-B);
    oper.push_back(A);
    oper.push_back(B);

    //N -> M 까지
    //+1, -1, +A, -A, +B, -B, *A, *B
    vector<int> dp(max(N, M) + 1, INT_MAX);

    queue<pair<int,int>> q;
    q.push({N, 0});

    while (!q.empty())
    {
        auto [current, cost] = q.front();
        q.pop();

        if (dp[current] <= cost) continue;
        dp[current] = cost;

        for (int i = 0; i < 8; i++)
        {
            int next = getNext(current, i);
            if (next < 0 || next > max(N, M)) continue;
            q.push({ next , cost + 1 });
        }
    }

    cout << dp[M];

    return 0;
}