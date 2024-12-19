#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int, int>> startPoints;
vector<vector<int>> board;
vector<bool> checked;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void MakeComb(vector<vector<int>>& comb, vector<int>& temp, int depth)
{
    if (temp.size() == M)
    {
        comb.push_back(temp);
        return;
    }

    for (int i = depth; i < startPoints.size(); i++)
    {
        if (checked[i]) continue;
        temp.push_back(i);
        checked[i] = true;
        MakeComb(comb, temp, i + 1);
        temp.pop_back();
        checked[i] = false;
    }
}

int BFS(vector<int> comb)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    int cnt = 0;

    for (auto idx : comb)
    {
        auto [y, x] = startPoints[idx];
        cnt++;
        dp[y][x] = 0;
        q.push({ y,x });
    }

    int result = 0;
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
            if (dp[newY][newX] != -1) continue;
            if (board[newY][newX] == 1) continue;

            dp[newY][newX] = dp[y][x] + 1;
            cnt++;
            result = max(result, dp[newY][newX]);

            q.push({ newY, newX });
        }
    }

    if (cnt == K) return result;
    return INT_MAX;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 1) K++;
            if (board[i][j] == 2) startPoints.push_back({ i,j });
        }
    }

    checked.resize(startPoints.size(), false);
    vector<vector<int>> comb;
    vector<int> temp;
    MakeComb(comb, temp, 0);

    int ans = INT_MAX;
    for (auto& c : comb)
    {
        ans = min(ans, BFS(c));
    }

    if (ans == INT_MAX) ans = -1;
    cout << ans;

    return 0;
}