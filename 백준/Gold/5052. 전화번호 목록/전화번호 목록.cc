#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, N;


int main() 
{
    INPUT_OPTIMIZE;

    cin >> T;

    while (T--)
    {
        cin >> N;

        bool flag = true;
        vector<string> strs;

        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;

            strs.push_back(str);
        }

        sort(strs.begin(), strs.end());

        unordered_set<string> hashSet;

        for (int i = 0; i < N; i++)
        {
            string prefix;

            for (int j = 0; j < strs[i].length(); j++)
            {
                prefix += strs[i][j];

                if (hashSet.count(prefix) != 0)
                {
                    flag = false;
                    break;
                }

            }

            if (!flag) break;
            hashSet.insert(prefix);
        }

            
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    

    return 0;
} 