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

int N;
pair<int, int> Goal(0, 7);

vector<int> dy = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
vector<int> dx = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

bool DFS(vector<vector<char>>& Maze, int depth, pair<int, int> Player)
{
    if (Player.first == Goal.first && Player.second == Goal.second)
    {
        return true;
    }

    bool bResult = false;
    for (int i = 0; i < 9; i++)
    {
        int newY = Player.first + dy[i];
        int newX = Player.second + dx[i];

        if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
        if (newY - depth < 0) return true;
        if (Maze[newY- depth][newX] == '#') continue;
        if (newY - (depth + 1) < 0) return true;
        if (Maze[newY - (depth + 1)][newX] == '#') continue;

        bResult = (bResult || DFS(Maze, depth + 1, { newY,newX }));
    }

    return bResult;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    N = 8;

    vector<vector<char>> Maze(N, vector<char>(N));
    pair<int, int> Player(7, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Maze[i][j];
        }
    }

    cout << DFS(Maze, 0, Player);

    return 0;
}