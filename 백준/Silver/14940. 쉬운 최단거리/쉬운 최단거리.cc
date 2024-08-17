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

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<int>> answer(N, vector<int>(M, INT_MAX));

    pair<int, int> start;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2) start = { i,j };
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    answer[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        int current = answer[y][x];
        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (answer[newY][newX] != INT_MAX) continue;
            if (board[newY][newX] == 0) continue;

            answer[newY][newX] = current + 1;
            q.push({ newY, newX });
        }
    }

    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0 ; j < M; j++)
        {
            if (answer[i][j] == INT_MAX)
            {
                if (board[i][j] == 0)  cout << 0 << " ";
                else cout << -1 << " ";
            }
            else cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}