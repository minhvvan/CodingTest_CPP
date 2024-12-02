#include <bits/stdc++.h>

using namespace std;

int N, ans = INT_MAX;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void bfs(vector<vector<int>>& rooms)
{
    deque<tuple<int, int, int>> dq;
    vector<vector<int>> visited(N, vector<int>(N, INT_MAX));
    dq.push_back({ 0,0,0 });

    while (!dq.empty())
    {
        auto [cost, y, x] = dq.front();
        dq.pop_front();

        if (visited[y][x] <= cost) continue;
        if (ans <= cost) continue;
        visited[y][x] = cost;

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
            if (newY == N - 1 && newX == N - 1)
            {
                ans = cost;
                return;
            }
            if (visited[newY][newX] <= cost) continue;

            if (rooms[newY][newX] == 0) dq.push_back({ cost + 1, newY, newX });
            else dq.push_front({ cost, newY, newX });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    //0: 검은방 1: 흰방
    vector<vector<int>> rooms(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < N; j++)
        {
            rooms[i][j] = str[j]-'0';
        }
    }

    bfs(rooms);
    cout << ans;

    return 0;
}