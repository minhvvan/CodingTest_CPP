#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, L;
vector<int> areas;

bool Check(int len)
{
    int cnt = 0;
    for (int i = 1; i < N + 2; i++)
    {
        int gap = areas[i] - areas[i - 1];
        if (gap % len == 0)
        {
            cnt += gap / len - 1;
        }
        else
        {
            cnt += gap / len;
        }
    }

    return cnt <= M;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M >> L;
    areas.resize(N + 2);
    
    int left = 1;
    int right = L;

    areas[0] = 0;
    areas[N + 1] = L;

    for (int i = 0; i < N; i++)
    {
        cin >> areas[i];
        if (i == 0) continue;
    }

    sort(areas.begin(), areas.end());

    int ans = right;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if (Check(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
} 