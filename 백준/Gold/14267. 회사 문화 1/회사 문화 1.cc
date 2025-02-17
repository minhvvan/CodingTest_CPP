#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> parent;
vector<int> compliment;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> M;
	parent.resize(N + 1, 0);
	compliment.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int p;
		cin >> p;

		if (p == -1) continue;

		parent[i] = p;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		compliment[a] += b;
	}

	/*
	* 부모에 대해 주어지고 자식을 알고있어야 함
	* 부모가 자식보다 수가 낮음
	* 부모는 한명 -> 자신의 부모거를 당겨오면 됨
	* 낮은 수부터 처리해야 함
	*/

	for (int i = 2; i <= N; i++)
	{
		compliment[i] += compliment[parent[i]];
	}

	for (int i = 1; i <= N; i++)
	{
		cout << compliment[i] << " ";
	}

	return 0;
}