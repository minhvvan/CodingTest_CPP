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

//남동북서
vector<int> dy = { 0, -1, 0, 1 };
vector<int> dx = { -1, 0, 1, 0 };

vector<vector<bool>> visited;
map<int, int> ClusterCnt;
map<int, set<int>> AdjCluster;
int C = 1;

void SeperateArea(vector<vector<int>>& Castle,vector<vector<int>>& Cluster, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({ i,j });
    Cluster[i][j] = C;
    ClusterCnt[C]++;
    visited[i][j] = true;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            //Blocked
            int newY = y + dy[k];
            int newX = x + dx[k];
            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;

            if (Cluster[newY][newX] != 0 && Cluster[newY][newX] != C)
            {
                AdjCluster[C].insert(Cluster[newY][newX]);
                AdjCluster[Cluster[newY][newX]].insert(C);
            }

            if ((Castle[y][x] & (1 << k))) continue;
            if (visited[newY][newX]) continue;

            visited[newY][newX] = true;
            Cluster[newY][newX] = C;
            ClusterCnt[C]++;

            q.push({ newY,newX });
        }
    }

    C++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    vector<vector<int>> Castle(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        vector<bool> temp(M, false);
        visited.push_back(temp);

        for (int j = 0; j < M; j++)
        {
            cin >> Castle[i][j];
        }
    }

    vector<vector<int>> Cluster(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j]) continue;

            SeperateArea(Castle, Cluster, i, j);
        }
    }

    cout << C-1 << "\n";

    int maxCnt = 0;
    for (auto [num, cnt] : ClusterCnt)
    {
        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt << "\n";

    int answer = 0;
    for (int i = 1; i < C; i++)
    {
        for (int j = i; j < C; j++)
        {
            if (AdjCluster[i].count(j) != 1) continue;
            answer = max(answer, ClusterCnt[i] + ClusterCnt[j]);
        }
    }

    cout << answer << "\n";

	return 0;
}