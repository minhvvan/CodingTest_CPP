#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define ull unsigned long long

using namespace std;
int N, M;
vector<ull> costs;

bool Check(ull X)
{
    ull cnt = 0;

    for (int i = 0; i < N; i++)
    {
        cnt += X / costs[i];
        if (cnt >= M) return true;
    }

    return cnt >= M;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;
    costs.resize(N);

    ull left = 0;
    ull right = INF;

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
        right = max(right, costs[i]);
    }

    right = right * M;
    ull ans = right;

    while (left <= right)
    {
        ull mid = (left + right) / 2;

        if (Check(mid))
        {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
} 