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

int N;

struct Word
{
    Word(string s) : str(s)
    {
        for (char spell = 'A'; spell <= 'Z'; spell++)
        {
            spellCount.insert({ spell, 0 });
        }

        for (auto c : str)
        {
            spellCount[c]++;
        }
    };

    string str;
    map<char, int> spellCount;

    bool operator==(const Word& Other)
    {
        int lengthDiff = abs((int)str.length() - (int)Other.str.length());
        if (lengthDiff > 1) return false;

        map<char, int> temp(spellCount);
        int same = 0;

        for (int i = 0; i < Other.str.length(); i++)
        {
            char spell = Other.str[i];
            if (temp[spell] > 0)
            {
                temp[spell]--;
                same++;
            }
        }

        if (lengthDiff == 0)
        {
            if (same == str.length() || same == str.length() - 1) return true;
        }
        else
        {
            int shortLength = min(str.length(), Other.str.length());
            if (same == shortLength) return true;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    string str;
    cin >> str;

    Word first(str);

    int ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        string temp;
        cin >> temp;

        Word current(temp);

        if (first == current) ans++;
    }

    cout << ans++;

    return 0;
}