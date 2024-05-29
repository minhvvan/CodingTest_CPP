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

vector<int> dy = { 0, -1, 0, 1 };
vector<int> dx = { -1, 0, 1, 0 };

enum DIR
{
    LEFT,
    UP,
    RIGHT,
    DOWN
};


int BFS(vector<vector<char>>& LaserMap, vector<pair<int, int>>& Targets)
{
    pair<int, int> Start = Targets[0];
    pair<int, int> End = Targets[1];

    int answer = INT_MAX;

    //pos, dir, mirror
    deque<tuple<pair<int, int>, int, int>> q;

    vector<vector<int>> visited(N, vector<int>(M, INT_MAX));
    visited[Start.first][Start.second] = 0;

    for (int i = 0; i < 4; i++)
    {
        int newY = Start.first + dy[i];
        int newX = Start.second + dx[i];

        if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
        if (LaserMap[newY][newX] == '*') continue;
        if (newY == End.first && newX == End.second) return 0;

        visited[newY][newX] = 0;
        q.push_back({ {newY,newX}, i, 0});
    }


    while (!q.empty())
    {
        auto [pos, dir, mirror] = q.front();
        q.pop_front();

        visited[pos.first][pos.second] = min(visited[pos.first][pos.second], mirror);

        for (int i = 0; i < 4; i++)
        {
            int newY = pos.first + dy[i];
            int newX = pos.second + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (LaserMap[newY][newX] == '*') continue;
            if (visited[newY][newX] <= mirror) continue;
            if (newY == End.first && newX == End.second)
            {
                if (i == dir) answer = min(answer, mirror);
                else answer = min(answer, mirror+1);
            }

            if (i == dir)
            {
                q.push_front({ { newY, newX }, i, mirror });
            }
            else
            {
                q.push_back({ {newY, newX}, i, mirror + 1 });
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    vector<vector<char>> LaserMap(N, vector<char>(M));
    vector<pair<int, int>> Targets;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> LaserMap[i][j];
            if (LaserMap[i][j] == 'C')
            {
                Targets.push_back({ i,j });
            }
        }
    }
    
    cout << BFS(LaserMap, Targets);

	return 0;
}