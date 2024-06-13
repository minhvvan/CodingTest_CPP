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

long long N;

bool IsInner(int y, int x)
{
    return (y >= 0 && y < N && x >= 0 && x < N);
}

int BFS(vector<vector<char>>& Room, vector<pair<int, int>>& Doors)
{
    int result = INT_MAX;
    auto Start = Doors[0];
    auto End = Doors[1];

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    vector<int> di = { 0, -1, 1 };

    //y, x, dir, mirror
    deque<tuple<int, int, int, int>> dq;
    vector<vector<int>> visited(N, vector<int>(N, 0));
    
    for (int i = 0; i < 4; i++)
    {
        int newY = Start.first + dy[i];
        int newX = Start.second + dx[i];

        if (!IsInner(newY, newX)) continue;
        if (Room[newY][newX] == '*') continue;

        dq.push_back({ Start.first, Start.second, i, 0 });
    }

    while (!dq.empty())
    {
        auto [y, x, dir, mirror] = dq.front();
        dq.pop_front();

        if (mirror >= result) continue;

        int iterCnt = Room[y][x] == '!' ? 3 : 1;
        for (int i = 0; i < iterCnt; i++)
        {
            int newDir = (dir + di[i] + 4) % 4;
            int addMirror = i > 0 ? 1 : 0;

            int newY = y + dy[newDir];
            int newX = x + dx[newDir];

            if (!IsInner(newY, newX)) continue;
            if (Room[newY][newX] == '*') continue;

            if (newY == End.first && newX == End.second)
            {
                result = min(result, mirror+ addMirror);
                continue;
            }

            if (addMirror == 1)
            {
                dq.push_back({ newY, newX, newDir, mirror+addMirror });
            }
            else
            {
                dq.push_front({ newY, newX, newDir, mirror });
            }
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<vector<char>> Room(N, vector<char>(N));
    vector<pair<int, int>> Doors;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Room[i][j];
            if (Room[i][j] == '#')
            {
                Doors.push_back({ i,j });
            }
        }
    }

    cout << BFS(Room, Doors);

    return 0;
}