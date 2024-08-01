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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> Lamps(M);
    for (int i = 0; i < M; i++)
    {
        cin >> Lamps[i];
    }

    int minHeight = max(Lamps[0], N-Lamps.back());
    for (int i = 1; i < M; i++)
    {
        int add = 0;
        if ((Lamps[i] - Lamps[i - 1]) % 2 == 1) add = 1;

        int diff = (Lamps[i] - Lamps[i - 1]) / 2 + add;
        minHeight = max(minHeight, diff);
    }

    cout << minHeight;

    return 0;
}