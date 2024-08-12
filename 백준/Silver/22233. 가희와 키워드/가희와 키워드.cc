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
#include <bitset>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    set<string> keywords;

    for (int i = 0; i < N; i++)
    {
        string keyword;
        cin >> keyword;

        keywords.insert(keyword);
    }

    for (int i = 0; i < M; i++)
    {
        string input;
        cin >> input;

        stringstream ss;
        ss.str(input);
        string out;
        while (getline(ss, out, ','))
        {
            auto itr = keywords.find(out);
            if (itr != keywords.end())
            {
                keywords.erase(out);
            }
        }

        cout << keywords.size() << "\n";
    }

    return 0;
}