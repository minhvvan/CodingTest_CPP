#include <bits/stdc++.h>

using namespace std;

int N;
string str;
vector<int> alpha(26, 0);

bool Check()
{
	int cnt = 0;
	for (int i = 0; i < alpha.size(); i++)
	{
		if (alpha[i] > 0) cnt++;
	}

	return cnt <= N;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N >> str;

	/*
	* N개의 문자열로 이루어진 가장 긴 연속 부분 수열
	* 26, 100'000
	* abbcaccba
	* 123323432
	* 각 알파벳의 개수를 관리
	* 투포인터
	*/

	int left = 0;
	int right = 0;

	alpha[str[right] - 'a']++;

	int ans = 0;
	while (++right < str.length())
	{
		alpha[str[right] - 'a']++;

		if (!Check())
		{
			while (--alpha[str[left++] - 'a'] > 0)
			{
			}
		}

		ans = max(ans, right - left + 1);
	}

	cout << ans;

	return 0;
}