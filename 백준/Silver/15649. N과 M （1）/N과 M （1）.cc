#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, M;
vector<bool> visited;

void DFS(vector<int>& temp, int idx)
{
	if (temp.size() == M)
	{
		for (auto n : temp)
		{
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		temp.push_back(i);
		DFS(temp, i);
		visited[i] = false;
		temp.pop_back();
	}
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> M;

	vector<int> temp;
	visited.resize(N + 1, false);

	for (int i = 1; i <= N; i++)
	{
		temp.push_back(i);
		visited[i] = true;
		DFS(temp, i);
		visited[i] = false;
		temp.pop_back();
	}

	return 0;
}