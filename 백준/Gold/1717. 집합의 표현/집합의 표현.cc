#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<int> links;

int Find(int a)
{
	if (links[a] == a) return a;
	return links[a] = Find(links[a]);
}

void Combine(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a > b) swap(a, b);
	links[b] = a;
}
	
int main()
{
    INPUT_OPTIMIZE;

	cin >> N >> M;
	links.resize(N + 1);

	for (int i = 0; i <= N; i++)
	{
		links[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int o, a, b;
		
		cin >> o >> a >> b;

		if (o == 0)
		{
			Combine(a, b);
		}
		else
		{
			a = Find(a);
			b = Find(b);

			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	

	return 0;
} 