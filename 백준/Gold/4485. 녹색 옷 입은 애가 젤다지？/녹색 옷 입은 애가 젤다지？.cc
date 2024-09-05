#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    int idx = 0;
    while (cin >> N)
    {
        if (N == 0) break;
        idx++;
        vector<vector<int>> cave(N,vector<int>(N));
        vector<vector<int>> visited(N,vector<int>(N, INT_MAX));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> cave[i][j];
            }
        }

        int ans = INT_MAX;
        visited[0][0] = cave[0][0];
        queue<pair<int, int>> q;
        q.push({ 0,0 });

        while (!q.empty())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
                if (newY == N - 1 && newX == N - 1)
                {
                    ans = min(ans, visited[y][x] + cave[newY][newX]);
                    continue;
                }
                if (visited[newY][newX] <= visited[y][x] + cave[newY][newX]) continue;

                visited[newY][newX] = visited[y][x] + cave[newY][newX];
                q.push({ newY,newX });
            }
        }

        cout << "Problem " << idx << ": " << ans << "\n";
    }

    return 0;
}