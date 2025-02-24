#include <bits/stdc++.h>

using namespace std;

string S;

bool IsPalindrome(int size)
{
	int ans = INT_MAX;

	//짝수 
	{
		bool flag = true;
		for (int i = 0; i < size; i++)
		{
			if (size + i >= S.size()) break;
			if (S[size - 1 - i] != S[size + i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			ans = min(ans, size * 2);
		}
	}

	//홀수
	{
		if (size * 2 > S.size())
		{
			bool flag = true;
			for (int i = 0; i < size; i++)
			{
				if (size + i >= S.size()) break;
				if (S[size - 2 - i] != S[size + i])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				ans = min(ans, size * 2 - 1);
			}
		}
	}

	if (ans != INT_MAX)
	{
		cout << ans;
		return true;
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> S;
	if (S.length() == 1)
	{
		cout << 1;
		return 0;
	}

	int mid = (S.length() + 1) / 2;
	for (int i = mid; i <= S.length(); i++)
	{
		if(IsPalindrome(i))
		{
			return 0;
		}
	}
	
	return 0;
}