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

vector<int> dy = { -1, 0 , 1, 0 };
vector<int> dx = { 0, 1 , 0, -1 };

void Print(vector<vector<int>>& Pool)
{
    for (auto row : Pool)
    {
        for (auto i : row)
        {
            cout << i;
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}

void BFS(vector<vector<int>>& Pool, int l)
{
    Pool[0][0] = l;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(Pool.size(), vector<bool>(Pool[0].size(), false));
    visited[0][0] = true;

    q.push({ 0,0 });

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= N + 2 || newX < 0 || newX >= M + 2) continue;
            if (visited[newY][newX]) continue;

            visited[newY][newX] = true;
            if (Pool[newY][newX] >= l) continue;

            Pool[newY][newX] = l;
            q.push({ newY, newX });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> Pool(N + 2, vector<int>(M + 2, 0));
    int maxNum = 0;
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= M; j++)
        {
            int t = temp[j - 1] - '0';
            Pool[i][j] = t;
            maxNum = max(maxNum, t);
        }
    }


    for (int i = 1; i <= maxNum; i++)
    {
        BFS(Pool, i);

        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= M; x++)
            {
                if (Pool[y][x] < i)
                {
                    Pool[y][x]++;
                    answer++;
                }
            }
        }
    }
       
    cout << answer;

	return 0;
}