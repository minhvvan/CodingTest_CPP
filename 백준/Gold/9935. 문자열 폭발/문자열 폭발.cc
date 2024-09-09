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

string str, bomb;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> bomb;

    deque<string> stack;
    string current;
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == bomb[current.size()])
        {
            current += c;
        }
        else if (c == bomb[0])
        {
            //새로 시작
            stack.push_back(current);
            current = c;
        }
        else
        {
            while (!stack.empty())
            {
                ans += stack.front();
                stack.pop_front();
            }

            ans += (current + c);
            current = "";
        }

        if (current == bomb)
        {
            if (!stack.empty())
            {
                current = stack.back();
                stack.pop_back();
            }
            else
            {
                current = "";
            }
        }
    }

    while (!stack.empty())
    {
        ans += stack.front();
        stack.pop_front();
    }
    ans += current;

    if (ans == "") cout << "FRULA";
    else cout << ans;

    return 0;
}