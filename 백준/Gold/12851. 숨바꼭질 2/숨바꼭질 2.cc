#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
const int MAX = 100'001;
vector<int> dp(MAX, MAX);
vector<int> path(MAX, 0);

int main() 
{
    INPUT_OPTIMIZE;

    /*
    * 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
    * 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지 인지
    * 
    * 
    * 거리별 min값을 유지하는 dp + bfs
    */

    cin >> N >> K;

    queue<int> q;
    q.push(N);

    dp[N] = 0;
    path[N] = 1;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        //오른쪽
        int right = current + 1;
        if (right < MAX)
        {
            if (dp[right] > dp[current] + 1)
            {
                dp[right] = dp[current] + 1;
                path[right] = 1;

                if (right != K) q.push(right);
            }
            else if (dp[right] == dp[current] + 1)
            {
                path[right]++;
                if (right != K) q.push(right);
            }
        }

        //왼쪽
        int left = current - 1;
        if (left >= 0)
        {
            if (dp[left] > dp[current] + 1)
            {
                dp[left] = dp[current] + 1;
                path[left] = 1;

                if (left != K) q.push(left);
            }
            else if (dp[left] == dp[current] + 1)
            {
                path[left]++;
                if (left != K) q.push(left);
            }
        }

        //텔포
        int teleport = current * 2;
        if (teleport < MAX)
        {
            if (dp[teleport] > dp[current] + 1)
            {
                dp[teleport] = dp[current] + 1;
                path[teleport] = 1;

                if (teleport != K) q.push(teleport);
            }
            else if (dp[teleport] == dp[current] + 1)
            {
                path[teleport]++;
                if (teleport != K) q.push(teleport);
            }
        }
    }

    cout << dp[K] << "\n" << path[K];

    return 0;
} 