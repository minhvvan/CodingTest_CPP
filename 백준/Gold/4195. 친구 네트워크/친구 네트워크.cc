#include <bits/stdc++.h>

using namespace std;

int T, N;

map<string, string> parent;
map<string, int> childrenCount;

string findRoot(string name)
{
	if (parent[name] == name) return name;
	if (parent[name] == "")
	{
		parent[name] = name;
		childrenCount[name] = 1;
		return name;
	}

	return parent[name] = findRoot(parent[name]);
}

int setFriend(string a, string b)
{
	a = findRoot(a);
	b = findRoot(b);

	if (parent[a] == parent[b]) return childrenCount[a];

	if (childrenCount[a] < childrenCount[b]) swap(a, b);

	parent[b] = a;
	childrenCount[a] += childrenCount[b];

	return childrenCount[a];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			string a, b;
			cin >> a >> b;

			cout << setFriend(a, b) << "\n";
		}

		parent.clear();
		childrenCount.clear();
	}

	return 0;
}