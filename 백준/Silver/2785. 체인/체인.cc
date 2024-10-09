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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    deque<int> chains(N);
    for (int i = 0; i < N; i++)
    {
        cin >> chains[i];
    }

    sort(chains.begin(), chains.end());

    int ans = 0;
    while (chains.size() != 1)
    {
        chains[0]--;
        ans++;

        chains[chains.size() - 2] += chains[chains.size() - 1];
        chains.pop_back();

        if (chains[0] == 0) chains.pop_front();
    }

    cout << ans;

    return 0;
}