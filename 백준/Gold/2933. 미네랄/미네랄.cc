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

using namespace std;

int N, M, K;
vector<int> dy = { -1,0,1,0 };
vector<int> dx = { 0,1,0,-1 };

void Print(vector<vector<char>>& Cave)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << Cave[i][j];
        }
        cout << "\n";
    }
}

void BFS(vector<vector<char>>& Cave, vector<vector<bool>>& visited, int startY, int startX)
{
    queue<pair<int, int>> q;
    q.push({ startY,startX });

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY <= 0 || newY > N || newX <= 0 || newX > M) continue;
            if (Cave[newY][newX] == '.') continue;
            if (visited[newY][newX]) continue;

            visited[newY][newX] = true;
            q.push({ newY,newX });
        }
    }

    return;
}

void MoveDown(vector<vector<char>>& Cave, vector<vector<bool>>& cluster, int down)
{
    for (int i = N; i > 0; i--)
    {
        for (int j =1; j <= M; j++)
        {
            if (cluster[i][j])
            {
                Cave[i][j] = '.';
                Cave[i + down][j] = 'x';
            }
        }
    }
}

int GetDown(vector<vector<char>>& Cave, vector<vector<bool>>& cluster)
{
    int down = N;

    for (int j = 1; j <= M; j++)
    {
        int low = -1;
        for (int i = N; i > 0; i--)
        {
            if (cluster[i][j])
            {
                low = i;
                break;
            }
        }

        if (low == -1) continue;
        int high = N+1;

        for (int i = N; i > low; i--)
        {
            if (Cave[i][j] == 'x')
            {
                if (!cluster[i][j]) high = i;
            }
        }

        down = min(down, high - low - 1);
    }

    if (down == N+1) return -1;
    return down;
}

void Throw(vector<vector<char>>& Cave, int h, int dir)
{
    int y = Cave.size() - h;
    int x = dir == 0 ? 1 : M;
    int dx = dir == 0 ? 1 : -1;

    pair<int, int> breakPoint({ -1,-1 });
    for (int i = 1; i <= M; i++)
    {
        if (Cave[y][x] == 'x')
        {
            Cave[y][x] = '.';
            breakPoint = { y,x };
            break;
        }

        x += dx;
    }

    if (breakPoint.first == -1 && breakPoint.second == -1) return;

    vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));
    vector<vector<bool>> cluster(N+1, vector<bool>(M+1, false));
    for (int j = 1; j <= M; j++)
    {
        if (Cave[N][j] == '.' || visited[N][j]) continue;
        BFS(Cave, visited, N, j);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (Cave[i][j] == 'x' && !visited[i][j])
            {
                cluster[i][j] = true;
            }
        }
    }

    int down = GetDown(Cave, cluster);
    if (down != -1) MoveDown(Cave, cluster, down);
}

void Sim(vector<vector<char>>& Cave, vector<int>& Sticks)
{
    int dir = 0;
    for (int i = 0; i < Sticks.size(); i++)
    {
        Throw(Cave, Sticks[i], dir);
        dir = (dir + 1) % 2;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<char>> Cave(N+1, vector<char>(M+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Cave[i][j];
        }
    }

    cin >> K;
    vector<int> Sticks(K);
    for (int i = 0; i < K; i++)
    {
        cin >> Sticks[i];
    }

    Sim(Cave, Sticks);
    Print(Cave);

    return 0;
}