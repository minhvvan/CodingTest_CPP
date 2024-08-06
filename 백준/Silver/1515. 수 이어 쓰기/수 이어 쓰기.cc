#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

string N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

	int num = 0, ptr = 0;

	while (num++ < 30000) 
	{
		string num2str = to_string(num);
		for (int i = 0; i < num2str.length(); i++) 
		{
			if (N[ptr] == num2str[i]) 
			{
				ptr++;
			}
			if (ptr == N.length())
			{
				cout << num;
				return 0;
			}
		}
	}

    return 0;
}