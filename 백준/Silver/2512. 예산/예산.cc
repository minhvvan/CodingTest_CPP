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
vector<int> Bugets;

bool GetPossible(int mid)
{
    int sum = 0;
    for (auto buget : Bugets)
    {
        if (buget < mid) sum += buget;
        else sum += mid;
    }

    return sum <= M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Bugets.assign(N, 0);

    int maxBuget = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> Bugets[i];
        maxBuget = max(maxBuget, Bugets[i]);
    }

    cin >> M;

    int left = 1;
    int right = maxBuget;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (GetPossible(mid)) left = mid + 1;
        else right = mid - 1;

        mid = (left + right) / 2;
    }

    cout << mid;

    return 0;
}