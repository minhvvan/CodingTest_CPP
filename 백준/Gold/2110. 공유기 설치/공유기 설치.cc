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

int N, C;
vector<long long> house;

bool canPossible(long long gap)
{
    //C개 설치 가능? mid간격
    long long target = house[0] + gap;
    long long cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (house[i] >= target)
        {
            cnt++;
            target = house[i] + gap;
        }
    }

    return C <= cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    house.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }

    sort(house.begin(), house.end());
    long long right = house.back() - house[0] + 1;
    long long left = 1;

    long long ans = 0;
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        if (canPossible(mid))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }

    cout << ans;

    return 0;
}