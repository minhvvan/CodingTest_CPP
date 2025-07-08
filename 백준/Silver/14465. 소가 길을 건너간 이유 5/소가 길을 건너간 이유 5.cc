#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, K, B;
vector<int> lights;
vector<int> sum;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> K >> B;

	lights.resize(B);
	sum.resize(N + 1);

	for (int i = 0; i < B; i++)
	{
		cin >> lights[i];
	}

	int idx = 0;
	sort(lights.begin(), lights.end());
	for (int i = 1; i <= N; i++)
	{
		if (lights[idx] == i)
		{
			sum[i] = sum[i - 1];
			idx++;
		}
		else 
		{
			sum[i] = sum[i - 1] + 1;
		}
	}

	int ans = MAX;
	for (int i = K; i <= N; i++)
	{
		ans = min(ans, K - (sum[i] - sum[i - K]));
	}

	cout << ans;
	
	return 0;
}