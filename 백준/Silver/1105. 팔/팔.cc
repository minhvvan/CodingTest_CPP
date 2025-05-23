#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int L, R;

int main() 
{
    INPUT_OPTIMIZE;
    
	string L, R;
	int min = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> R;

	if (L.size() != R.size()) 
	{
		cout << 0;
	}
	else 
	{
		for (int i = 0; i < L.size(); i++) 
		{
			if (L[i] != R[i]) 
			{
				break;
			}

			if (L[i] == R[i] && L[i] == '8') 
			{
				min++;
			}
		}

		cout << min;
	}

	return 0;
} 