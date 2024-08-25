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
#include <list>
#include <bitset>

using namespace std;

string S, T;

void reverse(string& str)
{
    string result;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    str = move(result);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> T;

    set<string> checked;
    queue<string> q;

    q.push(T);
    checked.insert(T);

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        if (current.length() < S.length()) break;

        //oper1
        {
            if (current.back() == 'A')
            {
                string newStr = current;
                newStr.erase(newStr.length() - 1);

                if (newStr == S)
                {
                    cout << 1;
                    return 0;
                }

                if (checked.count(newStr) == 0)
                {
                    checked.insert(newStr);
                    q.push(newStr);
                }
            }
            
            if(current[0] == 'B')
            {
                string newStr = current;
                reverse(newStr);
                newStr.erase(newStr.length() - 1);

                if (newStr == S)
                {
                    cout << 1;
                    return 0;
                }

                if (checked.count(newStr) == 0)
                {
                    checked.insert(newStr);
                    q.push(newStr);
                }
            }
        }
    }

    cout << 0;


    return 0;
}