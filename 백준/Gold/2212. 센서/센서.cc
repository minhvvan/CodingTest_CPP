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

int N, K;
vector<int> sensors;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> K;

    sensors.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end());

    vector<int> gaps;
    for (int i = 0; i < N-1; i++)
    {
        gaps.push_back(sensors[i + 1] - sensors[i]);
    }

    sort(gaps.begin(), gaps.end(), greater());

    int ans = 0;
    for (int i = K - 1; i < N-1; i++)
    {
        ans += gaps[i];
    }

    cout << ans;

    return 0;
}