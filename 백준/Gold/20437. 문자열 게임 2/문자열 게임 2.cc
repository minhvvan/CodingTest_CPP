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

int T, K;
string W;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> W >> K;

        map<char, vector<int>> characters;
        for (int i = 0 ; i < W.length(); i++)
        {
            characters[W[i]].push_back(i);
        }

        int shortest = W.length() + 1;
        int longest = 0;
        for (auto& [key, indexes] : characters)
        {
            if (indexes.size() < K) continue;

            for (int i = 0; i <= indexes.size()-K; i++)
            {
                shortest = min(shortest, indexes[i + K - 1] - indexes[i] + 1);
                longest = max(longest, indexes[i + K - 1] - indexes[i] + 1);
            }
        }

        if (shortest == W.length() + 1 || longest == 0) cout << -1;
        else cout << shortest << " " << longest;

        cout << "\n";
    }

    return 0;
}