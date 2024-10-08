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

int N, S, R;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> S >> R;

    vector<int> teams(N + 1, 1);
    for (int i = 0; i < S; i++)
    {
        int s;
        cin >> s;
        teams[s]--;
    }

    for (int i = 0; i < R; i++)
    {
        int r;
        cin >> r;
        teams[r]++;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (teams[i] > 1)
        {
            if (teams[i - 1] == 0)
            {
                teams[i]--;
                teams[i - 1]++;
            }
            else if(i < N && teams[i + 1] == 0)
            {
                teams[i]--;
                teams[i + 1]++;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (teams[i] == 0) ans++;
    }

    cout << ans;

    return 0;
}