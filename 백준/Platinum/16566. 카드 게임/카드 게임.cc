#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M, K;
vector<int> cards;
vector<int> submits;

vector<int> parents;

int Find(int idx)
{
	if (parents[idx] == idx) return idx;
	return parents[idx] = Find(parents[idx]);
}

void Union(int a)
{
	int p = Find(a);
	parents[a] = p + 1;
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N >> M >> K;
	
	cards.resize(M);
	parents.resize(M);
	submits.resize(K);

	for (int i = 0; i < M; i++)
	{
		parents[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> cards[i];
	}

	for (int i = 0; i < K; i++)
	{
		cin >> submits[i];
	}

	sort(cards.begin(), cards.end());

	for (int i = 0; i < K; i++)
	{
		auto pos = upper_bound(cards.begin(), cards.end(), submits[i]) - cards.begin();
		cout << cards[Find(pos)] << "\n";

		Union(pos);
	}

	return 0;
}