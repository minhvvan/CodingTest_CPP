#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

int main() 
{
    INPUT_OPTIMIZE;

	int n, k;
	cin >> n >> k;

	if (k >= n) 
	{
		cout << 0;
	}
	else 
	{
		int answer = 0;

		while (1) 
		{
			int cnt = 0;
			int temp = n;
			while (temp > 0) 
			{
				if (temp % 2 == 0) 
				{
					temp /= 2;
				}
				else 
				{
					temp /= 2;
					cnt++;
				}
			}

			//cnt가 k보다 작거나 같아지면 종료
			if (k >= cnt) break;

			n++;
			answer++;
		}

		cout << answer;
	}

    return 0;
} 