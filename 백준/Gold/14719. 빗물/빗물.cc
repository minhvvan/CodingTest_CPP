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

int H, W;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;

    vector<int> Board(W);
    vector<int> left(W, 0);
    vector<int> right(W, 0);
    for (int i = 0; i < W; i++)
    {
        cin >> Board[i];
    }

    for (int i = 1; i < W; i++)
    {
        left[i] = max(left[i - 1], Board[i - 1]);
    }

    for (int i = W-2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], Board[i + 1]);
    }

    int ans = 0;

    for (int i = 0; i < W; i++)
    {
        int temp = min(left[i], right[i]) - Board[i] < 0 ? 0 : min(left[i], right[i]) - Board[i];
        ans += temp;
    }

    cout << ans;

    return 0;
}