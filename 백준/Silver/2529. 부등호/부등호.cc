#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N;
vector<char> brackets;
vector<bool> visited;
string minNum = "987654321";
string maxNum = "0";

string Convert(vector<int>& current)
{
	string num = "";
	for (auto& n : current)
	{
		num += n + '0';
	}

	return num;
}

void DFS(int prev, int idx, vector<int>& current)
{
	if (idx == N)
	{
		auto num = Convert(current);

		minNum = min(minNum, num);
		maxNum = max(maxNum, num);
		return;
	}

	if (brackets[idx] == '<')
	{
		for (int i = prev + 1; i < 10; i++)
		{
			if (visited[i]) continue;
			
			visited[i] = true;
			current.push_back(i);
			DFS(i, idx + 1, current);
			current.pop_back();
			visited[i] = false;
		}
	}
	else
	{
		for (int i = prev - 1; i >= 0; i--)
		{
			if (visited[i]) continue;

			visited[i] = true;
			current.push_back(i);
			DFS(i, idx + 1, current);
			current.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N;
	brackets.resize(N);
	visited.resize(10, false);

	for (int i = 0; i < N; i++)
	{
		cin >> brackets[i];
	}

	vector<int> temp;
	for (int i = 0; i < 10; i++)
	{
		visited[i] = true;
		temp.push_back(i);
		DFS(i, 0, temp);
		temp.pop_back();
		visited[i] = false;
	}

	cout << maxNum << "\n" << minNum;

	return 0;
}