#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<pair<int,int>> A;
vector<pair<int,int>> B;

bool cmp(pair<int,int> a, pair<int,int> b) 
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back({ a, i });
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int b;
		cin >> b;
		B.push_back({ b, i });
	}

	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);

	int idxA = 0, idxB = 0;
	int rightA = 0, rightB = 0;

	vector<int> ans;
	while (idxA < N && idxB < M)
	{
		if (A[idxA].first == B[idxB].first)
		{
			if (rightA > A[idxA].second) idxA++;
			else if (rightB > B[idxB].second) idxB++;
			else
			{
				rightA = A[idxA].second;
				rightB = B[idxB].second;

				ans.push_back(A[idxA].first);

				idxA++;
				idxB++;
			}
		}
		else if (A[idxA].first > B[idxB].first)
		{
			idxA++;
		}
		else
		{
			idxB++;
		}
	}

	cout << ans.size() << "\n";
	for (auto num : ans)
	{
		cout << num << " ";
	}

	return 0;
}