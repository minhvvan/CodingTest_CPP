#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9
#define MAX 987654321

using namespace std;
int N, K;
string input;

int main()
{
	INPUT_OPTIMIZE;
	
	cin >> N >> K;
	cin >> input;

	vector<int> temp;
	for (int i = 0; i < N; i++)
	{
		int num = input[i] - '0';
		while (K > 0 && !temp.empty() && temp.back() < num)
		{
			temp.pop_back();
			K--;
		}

		temp.push_back(num);
	}
		
	while (K > 0)
	{
		K--;
		temp.pop_back();
	}

	string ans;
	for (int i = 0; i < temp.size(); i++)
	{
		ans += temp[i] + '0';
	}

	cout << ans;
}