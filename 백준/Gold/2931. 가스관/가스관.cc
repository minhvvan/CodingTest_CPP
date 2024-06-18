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
vector<vector<char>> Possible(4);

int ChangeDir(char pipe, int dir)
{
    if (pipe == '1')
    {
        if (dir == 0) dir = 1;
        if (dir == 3) dir = 2;
    }
    else if (pipe == '2')
    {
        if (dir == 2) dir = 1;
        if (dir == 3) dir = 0;
    }
    else if (pipe == '3')
    {
        if (dir == 1) dir = 0;
        if (dir == 2) dir = 3;
    }
    else if (pipe == '4')
    {
        if (dir == 1) dir = 2;
        if (dir == 0) dir = 3;
    }

    return dir;
}

bool Simulate(vector<vector<char>>& Gas, pair<int,int> pos, pair<int,int>& end, int dir)
{
    bool bResult = false;
    while (true)
    {
        int& newY = pos.first;
        int& newX = pos.second;
        newY += dy[dir];
        newX += dx[dir];

        if (newY <= 0 || newY > N || newX <= 0 || newX > M) break;
        if (newY == end.first && newX == end.second)
        {
            bResult = true;
            break;
        }

        if (Gas[newY][newX] == '.') break;

        bool bPossible = false;
        for (int j = 0; j < 4; j++)
        {
            if (Possible[dir][j] == Gas[newY][newX])
            {
                bPossible = true;
                break;
            }
        }

        if (!bPossible) break;
        dir = ChangeDir(Gas[newY][newX], dir);
    }

    return bResult;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<char>> Gas(N+1, vector<char>(M+1));
    pair<int, int> pos;
    pair<int, int> end;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Gas[i][j];
            if (Gas[i][j] == 'M') pos = { i,j };
            if (Gas[i][j] == 'Z') end = { i,j };
        }
    }

    Possible[0].push_back('|');
    Possible[0].push_back('+');
    Possible[0].push_back('1');
    Possible[0].push_back('4');

    Possible[1].push_back('-');
    Possible[1].push_back('+');
    Possible[1].push_back('3');
    Possible[1].push_back('4');

    Possible[2].push_back('|');
    Possible[2].push_back('+');
    Possible[2].push_back('2');
    Possible[2].push_back('3');

    Possible[3].push_back('-');
    Possible[3].push_back('+');
    Possible[3].push_back('1');
    Possible[3].push_back('2');

    int dir = -1;

    for (int i = 0; i < 4; i++)
    {
        int newY = pos.first + dy[i];
        int newX = pos.second + dx[i];

        if (newY <= 0 || newY > N || newX <= 0 || newX > M) continue;
        if (Gas[newY][newX] == '.') continue;

        for (int j = 0; j < 4; j++)
        {
            if (Possible[i][j] == Gas[newY][newX])
            {
                dir = i;
                break;
            }
        }
    }

    while (true)
    {
        int newY = pos.first;
        int newX = pos.second;
        newY += dy[dir];
        newX += dx[dir];

        if (Gas[newY][newX] == '.')
        {
            for (int i = 0; i < 4; i++)
            {
                Gas[newY][newX] = Possible[dir][i];
                if (Simulate(Gas, pos, end, dir))
                {
                    cout << newY << " " << newX << " " << Possible[dir][i];
                    return 0;
                }
            }

            break;
        }

        dir = ChangeDir(Gas[newY][newX], dir);
        pos = { newY, newX };
    }

    return 0;
}