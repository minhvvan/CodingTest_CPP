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
int H, W, N, M;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> N >> M;

    int widthCnt = W / (M + 1);
    int heihgtCnt = H / (N + 1);

    if (W % (M + 1) != 0)
    {
        widthCnt++;
    }

    if (H % (N + 1) != 0)
    {
        heihgtCnt++;
    }

    cout << widthCnt * heihgtCnt;

    return 0;
}