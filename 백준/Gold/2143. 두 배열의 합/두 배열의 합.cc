#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> A;
vector<int> B;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
	}

	for (int i = 0; i < N; i++) 
	{
		int sum = A[i];
		for (int j = i + 1; j < N; j++) 
		{
			sum += A[j];
			A.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) 
	{
		int sum = B[i];
		for (int j = i + 1; j < M; j++) 
		{
			sum += B[j];
			B.push_back(sum);
		}
	}

	sort(B.begin(), B.end());

	long long ans = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int target = T - A[i];

		int first = lower_bound(B.begin(), B.end(), target) - B.begin();
		int last = upper_bound(B.begin(), B.end(), target) - B.begin();

		ans += last - first;
	}

	cout << ans;

	return 0;
}