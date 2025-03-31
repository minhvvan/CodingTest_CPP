#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int K, L;
unordered_map<string, int> filtered;
vector<pair<string, int>> temp;

int main() 
{
	INPUT_OPTIMIZE;

	cin >> K >> L;

	for (int i = 0; i < L; i++)
	{
		string num;
		cin >> num;

		filtered[num] = i;
	}

	for (auto& [num, idx] : filtered)
	{
		temp.push_back({ num,idx });
	}

	sort(temp.begin(), temp.end(), [](pair<string, int>& a, pair<string, int>& b) {
		return a.second < b.second;
		});

	for (int i = 0 ; i < K; i++)
	{
		if (temp.size() <= i) break;
		cout << temp[i].first << "\n";
	}

	return 0;
}