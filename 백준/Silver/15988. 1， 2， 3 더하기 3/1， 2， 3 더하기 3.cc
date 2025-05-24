#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T;
vector<long long> dp;
const int MOD = 1'000'000'009;
const int MAX = 1'000'000;

int main() 
{
    INPUT_OPTIMIZE;
    
    cin >> T;

    dp.resize(MAX + 1, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= MAX; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    while (T--)
    {
        int N;
        cin >> N;

        cout << dp[N] << "\n";
    }

	return 0;
} 