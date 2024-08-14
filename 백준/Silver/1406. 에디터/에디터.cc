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

string str;
int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> N;
    list<char> editor;

    for (char c : str)
    {
        editor.push_back(c);
    }

    auto cursor = editor.end();
    for (int i = 0; i < N; i++)
    {
        char oper;
        cin >> oper;

        if (oper == 'P')
        {
            char x;
            cin >> x;

            if (cursor == editor.end())
            {
                editor.push_back(x);
                cursor = editor.end();
            }
            else
            {
                editor.insert(cursor, x);
            }
        }
        else if (oper == 'L')
        {
            if (cursor == editor.begin()) continue;
            cursor--;
        }
        else if (oper == 'D')
        {
            if (cursor == editor.end()) continue;
            cursor++;
        }
        else if (oper == 'B')
        {
            if (cursor == editor.begin()) continue;
            if (cursor == editor.end())
            {
                editor.pop_back();
                cursor = editor.end();
            }
            else
            {
                auto copied = cursor;
                editor.erase(--copied);
            }
        }
    }

    for (auto c : editor)
    {
        cout << c;
    }

    return 0;
}