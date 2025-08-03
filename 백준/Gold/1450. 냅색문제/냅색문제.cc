#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, C;
vector<int> weights;
vector<int> lComb, rComb;

void MakeComb(vector<int>& v, int idx, int w, int end)
{
	if (w > C) return;
	if (idx == end)
	{
		v.push_back(w);
		return;
	}

	MakeComb(v, idx + 1, w, end);
	MakeComb(v, idx + 1, w + weights[idx], end);
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> C;

	weights.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> weights[i];
	}

	MakeComb(lComb, 0, 0, N / 2);
	MakeComb(rComb, N / 2, 0, N);

	sort(rComb.begin(), rComb.end());
	long long ans = 0;

	for (auto& x : lComb)
	{
		ans += upper_bound(rComb.begin(), rComb.end(), C - x) - rComb.begin();
	}

	cout << ans;

	return 0;
}