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

int N, M;
vector<int> ladder(101, 0);
vector<int> snake(101, 0);

int bfs()
{
    //1 to 100
    queue<int> q;
    vector<bool> visited(101, false);
    q.push(1);

    int cnt = 1;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int current = q.front();
            q.pop();

            for (int j = 1; j <= 6; j++)
            {
                int next = current + j;
                if (next > 100) continue;
                if (next == 100) return cnt;
                if (visited[next]) continue;

                visited[next] = true;
                if (ladder[next] != 0) q.push(ladder[next]);
                else if (snake[next] != 0) q.push(snake[next]);
                else q.push(next);
            }
        }

        cnt++;
    }

    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    cout << bfs();

    return 0;
}