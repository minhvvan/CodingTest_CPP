#include <bits/stdc++.h>

using namespace std;

int K;
vector<vector<int>> tree;
vector<int> nodes;

void insertTree(int depth, int start, int end) 
{
	if (start >= end) return;

	int mid = (start + end) / 2;
	tree[depth].push_back(nodes[mid]);
	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid + 1, end);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> K;
	tree.resize(K, vector<int>());
	nodes.resize(pow(2, K) - 1);

	for (int i = 0; i < pow(2, K) - 1; i++)
	{
		cin >> nodes[i];
	}

	insertTree(0, 0, pow(2, K) - 1);

	for (int i = 0; i < K; i++)
	{
		for (auto node : tree[i])
		{
			cout << node << " ";
		}

		cout << "\n";
	}

	return 0;
}