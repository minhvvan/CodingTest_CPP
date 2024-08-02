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

int N;
const long long MAX = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<long long> dists(N - 1);
    vector<long long> costs(N);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> dists[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    long long ans = 0;
    long long minCost = LLONG_MAX;
    for (int i = 0; i < N-1; i++)
    {
        minCost = min(minCost, costs[i]);
        ans += minCost * dists[i];
    }

    cout << ans;

    return 0;
}