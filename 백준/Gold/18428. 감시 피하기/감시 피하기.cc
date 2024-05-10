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
vector<pair<int, int>> Teachers;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

bool Check(vector<vector<char>>& School)
{
    for (auto& [y, x] : Teachers)
    {
        for (int i = 0; i < 4; i++)
        {
            int newY = y;
            int newX = x;

            while (true)
            {
                newY += dy[i];
                newX += dx[i];

                if (newY < 0 || newY >= School.size() || newX < 0 || newX >= School.size()) break;
                if (School[newY][newX] == 'O') break;
                if (School[newY][newX] == 'S') return false;
            }
        }
    }

    return true;
}

bool DFS(vector<pair<int, int>>& Obstacles, vector<vector<char>>& School, int depth, int idx)
{
    if (depth == 3)
    {
        return Check(School);
    }

    for (int i = idx; i < Obstacles.size(); i++)
    {
        School[Obstacles[i].first][Obstacles[i].second] = 'O';
        bool bResult = DFS(Obstacles, School, depth + 1, i + 1);
        School[Obstacles[i].first][Obstacles[i].second] = 'X';

        if (bResult) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> Students;
    vector<vector<char>> School(N, vector<char>(N));
    vector<pair<int, int>> Obstacles;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char temp;
            cin >> temp;
            School[i][j] = temp;

            if (temp == 'S') Students.push_back({ i,j });
            else if (temp == 'T') Teachers.push_back({ i,j });
        }
    }


    set<pair<int, int>> temp;

    for (auto& [y, x] : Teachers)
    {
        for (int i = 0; i < 4; i++)
        {
            int newY = y;
            int newX = x;

            while (true)
            {
                newY += dy[i];
                newX += dx[i];

                if (newY < 0 || newY >= N || newX < 0 || newX >= N) break;
                if (School[newY][newX] != 'X') break;
            
                temp.insert({ newY, newX });
            }
        }
    }

    Obstacles.assign(temp.begin(), temp.end());

    if (DFS(Obstacles, School, 0, 0)) cout << "YES";
    else cout << "NO";

    return 0;
}