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

enum type
{
    Consonant,
    Gather
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<char> Gather = { 'a', 'e', 'i', 'o', 'u' };

    while (true)
    {
        string input;
        cin >> input;

        if (input == "end") break;

        bool bPossible = true;
        bool bGather = false;
        //(자음 = 0, 모음 = 1), cnt
        pair<int, int> Continuity;
        char prev = input[0];
        for (int i = 0; i < input.length(); i++)
        {
            //조건 2
            if (Gather.count(input[i]) == 1)
            {
                //조건 1
                bGather = true;
                if (Continuity.first == type::Gather)
                {
                    Continuity.second++;
                }
                else 
                {
                    Continuity.first = type::Gather;
                    Continuity.second = 1;
                }
            }
            else
            {
                if (Continuity.first == type::Consonant)
                {
                    Continuity.second++;
                }
                else
                {
                    Continuity.first = type::Consonant;
                    Continuity.second = 1;
                }
            }

            if (Continuity.second == 3)
            {
                bPossible = false;
                break;
            }

            if (i == 0) continue;

            //조건 3
            if (prev == input[i] && (prev != 'e' && prev != 'o'))
            {
                bPossible = false;
                break;
            }

            prev = input[i];
        }

        bPossible &= bGather;

        if (bPossible) cout << "<" << input << "> is acceptable.\n";
        else cout << "<" << input << "> is not acceptable.\n";
    }


    return 0;
}