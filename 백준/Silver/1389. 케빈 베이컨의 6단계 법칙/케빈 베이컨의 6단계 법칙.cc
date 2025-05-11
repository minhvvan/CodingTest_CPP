#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<int>> dist;

const int MAX = 987654321;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    dist.resize(N + 1, vector<int>(N + 1, MAX));

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        dist[a][b] = 1;
        dist[b][a] = 1;
    }


    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int minDist = MAX;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += dist[i][j];
        }

        if (minDist > sum)
        {
            minDist = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
} 