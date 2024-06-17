#include <stdio.h>
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

using namespace std;

int N, M;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int dist[11][21][21];

void BFS(vector<vector<char>> Room, vector<pair<int, int>>& dirty, int idx)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            dist[idx][x][y] = INT_MAX;
        }
    }

    queue<pair<int, int>> q;
    dist[idx][dirty[idx].first][dirty[idx].second] = 0;
    q.push(dirty[idx]);

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (Room[newY][newX] == 'x') continue;
            if (dist[idx][newY][newX] != INT_MAX) continue;

            dist[idx][newY][newX] = dist[idx][y][x] + 1;
            q.push({ newY, newX });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    while (true)
    {
        cin >> M >> N;
        if (N == 0 && M == 0) break;
        
        int ans = INT_MAX;

        vector<vector<char>> Room(N, vector<char>(M));
        pair<int, int> robot;
        vector<pair<int, int>> dirty;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> Room[i][j];
                if (Room[i][j] == 'o') robot = { i,j };
                if (Room[i][j] == '*') dirty.push_back({ i,j });
            }
        }

        dirty.push_back(robot);

        for (int i = 0; i < dirty.size(); i++)
        {
            BFS(Room, dirty, i);
        }

        int currentIdx = dirty.size() - 1;
        vector<int> order;
        for (int i = 0; i < currentIdx; i++)
        {
            order.push_back(i);
        }

        do
        {
            int current = 0;
            currentIdx = dirty.size() - 1;

            for (int i = 0; i < order.size(); i++)
            {
                int nextIdx = order[i];
                if (dist[currentIdx][dirty[nextIdx].first][dirty[nextIdx].second] == INT_MAX)
                {
                    current = INT_MAX;
                    break;
                }

                current += dist[currentIdx][dirty[nextIdx].first][dirty[nextIdx].second];

                if (current >= ans) break;
                currentIdx = nextIdx;
            }

            ans = min(ans, current);
        } while (next_permutation(order.begin(), order.end()));

        if (ans == INT_MAX) ans = -1;
        cout << ans << "\n";
    }


    return 0;
}