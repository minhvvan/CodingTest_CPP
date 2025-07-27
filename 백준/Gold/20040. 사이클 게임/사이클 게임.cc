#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<int> parent;

int Find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		if (a > b) swap(a, b);
		parent[b] = a;
	}
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> M;
	parent.resize(N);

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		a = Find(a);
		b = Find(b);

		if (a == b)
		{
			cout << i + 1;
			return 0;
		}

		Union(a, b);
	}

	cout << 0;
}