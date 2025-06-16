#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
vector<int> dolls;
double ans = 987654321;

double Calc(vector<int>& temp)
{
	int sum = 0;
	for (auto& num : temp)
	{
		sum += num;
	}

	double m = (double)sum / temp.size();

	double n = 0;
	for (auto& num : temp)
	{
		n += (num - m) * (num - m);
	}

	n /= temp.size();

	return sqrt(n);
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> K;

	dolls.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> dolls[i];
	}

	for (int i = 0; i < N; i++)
	{
		vector<int> temp;

		for (int j = i; j < N; j++)
		{
			temp.push_back(dolls[j]);

			if (temp.size() >= K)
			{
				auto result = Calc(temp);
				ans = min(ans, result);
			}
		}
	}

	cout.precision(10);
	cout << ans;

	return 0;
}