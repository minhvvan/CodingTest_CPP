#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
int MAX = 1'000'000;
vector<int> buckets(MAX + 1, 0);

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int g, x;
        cin >> g >> x;

        buckets[max(x - K, 0)] += g;
        buckets[min(x + K + 1, MAX)] -= g;
    }

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < MAX; i++)
    {
        sum += buckets[i];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}