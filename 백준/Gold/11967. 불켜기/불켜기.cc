#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N, M;

int BFS(vector<vector<vector<pair<int, int>>>>& Lights)
{
    int result = 0;

    queue<pair<int, int>> q;
    q.push({ 0,0 });

    vector<vector<bool>> LightOn(N, vector<bool>(N, false));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    LightOn[0][0] = true;
    result++;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (auto [lightY, lightX] : Lights[y][x])
        {
            if (LightOn[lightY][lightX]) continue;
            LightOn[lightY][lightX] = true;
            result++;

            for (int i = 0; i < 4; i++)
            {
                int prevY = lightY + dy[i];
                int prevX = lightX + dx[i];
                if (prevY < 0 || prevY >= N || prevX < 0 || prevX >= N) continue;

                if (visited[prevY][prevX]) q.push({ prevY, prevX });
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
            if (!LightOn[newY][newX]) continue;
            if (visited[newY][newX]) continue;

            visited[newY][newX] = true;
            q.push({ newY,newX });
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<vector<pair<int, int>>>> Lights(N, vector<vector<pair<int, int>>>(N));

    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;

        cin >> y >> x >> a >> b;
        Lights[y-1][x-1].push_back({ a-1,b-1 });
    }

    cout << BFS(Lights);

	return 0;
}