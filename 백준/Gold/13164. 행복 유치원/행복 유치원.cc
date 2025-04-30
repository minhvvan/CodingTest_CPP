#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
vector<int> kids;
vector<int> diff;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> K;

    kids.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> kids[i];
        if (i == 0) continue;
        diff.push_back(kids[i] - kids[i - 1]);
    }

    sort(diff.begin(), diff.end());

    long long ans = 0;
    for (int i = 0; i < N - K; i++)
    {
        ans += diff[i];
    }

    cout << ans;

    return 0;
} 