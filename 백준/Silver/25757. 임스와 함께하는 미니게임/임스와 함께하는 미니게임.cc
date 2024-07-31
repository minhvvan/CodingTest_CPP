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

int N, M;
char Type;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Type;

    map<char, int> Nums = { {'Y', 1}, {'F', 2}, {'O', 3} };

    M = Nums[Type];

    int ans = 0;
    vector<string> round;
    set<string> played;
    for (int i = 0; i < N; i++)
    {
        string current;
        cin >> current;

        if (played.count(current) == 1) continue;

        round.push_back(current);

        if (round.size() == M)
        {
            for (auto r : round)
            {
                played.insert(r);
            }

            round.clear();
            ans++;
        }
    }

    cout << ans;
    return 0;
}