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

    int P, M, N;
    cin >> P >> M >> N;

    vector<int> PizzaA(M);
    vector<int> PizzaB(N);
    map<int, int> sumA;
    map<int, int> sumB;
    int ans = 0;

    {
        int temp = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> PizzaA[i];
            temp += PizzaA[i];
        }
        sumA[temp]++;
    }

    {
        int temp = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> PizzaB[i];
            temp += PizzaB[i];
        }
        sumB[temp]++;
    }


    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = i; j < i + M - 1; j++)
        {
            sum += PizzaA[j % M];
            sumA[sum]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < i + N - 1; j++)
        {
            sum += PizzaB[j % N];
            sumB[sum]++;
        }
    }

    for (auto [a, cnt] : sumA)
    {
        int last = P - a;
        if (a == P) ans += cnt;
        else if (sumB[last] != 0) ans += cnt * sumB[last];
    }

    for (auto [b, cnt] : sumB)
    {
        if (b == P) ans += cnt;
    }

    cout << ans;

    return 0;
}