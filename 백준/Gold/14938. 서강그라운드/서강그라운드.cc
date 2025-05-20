#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

int N, M, R;
vector<int> items;
vector<vector<int>> dist;
const int MAX = 987'654'321;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M >> R;

    items.resize(N + 1);
    dist.resize(N + 1, vector<int>(N + 1, MAX));

    for (int i = 1; i <= N; i++)
    {
        cin >> items[i];
    }

    for (int i = 0; i < R; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }


    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] > M) continue;
            sum += items[j];
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
} 