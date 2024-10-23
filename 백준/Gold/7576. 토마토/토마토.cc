#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> M >> N;

    vector<vector<int>> box(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, int>> q;

    int total = N * M;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push({ i, j });
                visited[i][j] = true;
            }

            if (box[i][j] == 1) cnt++;
            else if(box[i][j] == -1) total--;
        }
    }

    if (cnt == total)
    {
        cout << 0;
        return 0;
    }

    int ans = 0;
    
    while (!q.empty())
    {
        int size = q.size();

        for (int t = 0; t < size; t++)
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
                if (visited[newY][newX]) continue;
                if (box[newY][newX] == -1) continue;

                cnt++;
                visited[newY][newX] = true;
                q.push({ newY, newX });
            }
        }

        ans++;
        if (cnt == total) break;
    }

    if (cnt == total) cout << ans;
    else cout << -1;

    return 0;
}