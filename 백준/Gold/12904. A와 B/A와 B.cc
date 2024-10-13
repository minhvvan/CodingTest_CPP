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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

string S, T;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> S >> T;

    queue<string> q;
    set<string> checked;
    q.push(T);
    checked.insert(T);

    while (!q.empty())
    {
        auto str = q.front();
        q.pop();

        if (str == S)
        {
            cout << 1;
            return 0;
        }

        //Add A
        {
            auto temp = str;
            if (temp.back() == 'A')
            {
                temp.pop_back();
                if (checked.count(temp) == 0)
                {
                    q.push(temp);
                    checked.insert(temp);
                }
            }
        }

        //reverse + B
        {
            auto temp = str;
            if (temp.back() == 'B')
            {
                temp.pop_back();
                reverse(temp.begin(), temp.end());
                if (checked.count(temp) == 0)
                {
                    q.push(temp);
                    checked.insert(temp);
                }
            }
        }
    }

    cout << 0;

    return 0;
}