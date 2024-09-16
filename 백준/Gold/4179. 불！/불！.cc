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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int R, C;
int ans = INT_MAX;

vector<vector<bool>> visited;
vector<vector<char>> maze;
vector<pair<int,int>> fires;
pair<int, int> pos;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void bfs()
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> next;
    q.push(pos);
    for (auto& fire : fires) next.push(fire);

    int level = 1;

    while (!q.empty())
    {
        int size = q.size();
        queue<pair<int, int>> temp;

        //burn
        while(!next.empty())
        {
            auto [y, x] = next.front();
            next.pop();

            for (int i = 0; i < 4; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
                if (maze[newY][newX] == '#') continue;
                if (maze[newY][newX] == 'F') continue;

                maze[newY][newX] = 'F';
                temp.push({ newY,newX });
            }
        }

        for (int s = 0; s < size; s++)
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (newY < 0 || newY >= R || newX < 0 || newX >= C)
                {
                    ans = min(ans, level);
                    return;
                }
                if (maze[newY][newX] == 'F') continue;
                if (maze[newY][newX] == '#') continue;
                if (visited[newY][newX]) continue;

                visited[newY][newX] = true;
                q.push({ newY, newX });
            }
        }

        level++;
        next = move(temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int answer = 0;
    cin >> R >> C;

    maze.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') pos = { i,j };
            if (maze[i][j] == 'F') fires.push_back({ i,j });
        }
    }

    visited[pos.first][pos.second] = true;

    bfs();
    
    if (ans == INT_MAX) cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}