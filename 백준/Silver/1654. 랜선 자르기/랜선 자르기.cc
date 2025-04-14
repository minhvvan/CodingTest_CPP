#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
vector<long long> lines;

bool Check(long long len)
{
    long long cnt = 0;

    for (auto& line : lines)
    {
        cnt += line / len;
    }

    return cnt >= N;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> K >> N;

    lines.resize(K);

    long long left = 1;
    long long right = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> lines[i];
        right = max(right, lines[i]);
    }

    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (Check(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
} 