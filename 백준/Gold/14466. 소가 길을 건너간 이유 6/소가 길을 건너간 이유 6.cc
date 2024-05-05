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

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

bool BFS(pair<int,int>& Start, pair<int, int>& End, vector<vector<vector<pair<int, int>>>>& farm)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(farm.size(), vector<bool>(farm.size(), false));

    q.push({ Start.first, Start.second });
    visited[Start.first][Start.second] = true;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (auto [newY, newX] : farm[y][x])
        {
            if (newY <= 0 || newY >= farm.size() || newX <= 0 || newX >= farm.size()) continue;
            if (visited[newY][newX]) continue;
            if (newY == End.first && newX == End.second) return true;

            visited[newY][newX] = true;
            q.push({ newY, newX });
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, R;
    cin >> N >> K >> R;

    map<pair<int, int>, set<pair<int, int>>> cross;
    vector<vector<vector<pair<int, int>>>> farm(N + 1, vector<vector<pair<int, int>>>(N + 1));
    vector<pair<int, int>> cows;

    for (int i = 0; i < R; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cross[{r1, c1}].insert({ r2, c2 });
        cross[{r2, c2}].insert({ r1, c1 });
    }

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        cows.push_back({ r,c });
    }

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            for (int i = 0; i < 4; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY <= 0 || newY > N || newX <= 0 || newX > N) continue;

                if (cross[{ y, x }].count({ newY, newX }) == 0)
                {
                    farm[y][x].push_back({ newY, newX });
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < cows.size(); i++)
    {
        for (int j = i + 1; j < cows.size(); j++)
        {
            if (!BFS(cows[i], cows[j], farm)) answer++;
        }
    }

    cout << answer;

    return 0;
}