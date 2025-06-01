#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, K, P[1001], cnt[1001], dp[10001];

int main()
{
    INPUT_OPTIMIZE;

	cin >> T >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> P[i] >> cnt[i];
    }

    dp[0] = 1;

    for (int i = 0; i < K; i++) 
    {
        for (int j = T; j >= 1; j--) 
        {
            int sum = 0;
            for (int k = 0; k < cnt[i]; k++) 
            {
                sum += P[i];
                if (j - sum >= 0 && dp[j - sum] > 0) dp[j] += dp[j - sum];
            }
        }
    }
	
	cout << dp[T];

	return 0;
} 