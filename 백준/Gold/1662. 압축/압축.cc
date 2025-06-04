#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
string str;
vector<int> letters;

int main()
{
	INPUT_OPTIMIZE;

	cin >> str;

    for (int i = 0; i < str.size(); i++) 
    {
        if (str[i] == '(')
        {
            letters.push_back(-1);
        }
        else if (isalnum(str[i])) 
        {
            if (i < str.size() - 1 && str[i + 1] == '(')
            {
                letters.push_back(str[i] - '0');
            }
            else
            {
                letters.push_back(1);
            }
        }
        else 
        {
            int len = 0;
            while (letters.back() != -1) 
            {
                len += letters.back();
                letters.pop_back();
            }

            letters.pop_back();
            len *= letters.back();
            letters.pop_back();

            letters.push_back(len);
        }
    }

    int ans = 0;
    while (!letters.empty()) 
    {
        ans += letters.back();
        letters.pop_back();
    }

	cout << ans;

	return 0;
}