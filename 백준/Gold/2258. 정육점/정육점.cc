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

long long N, M;

bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    vector<pair<long long, long long>> meats;
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        meats.push_back({ w, v });
    }

    sort(meats.begin(), meats.end(), cmp);

    long long sum = meats[0].first;
    long long temp = meats[0].second;
    long long ans = LLONG_MAX;

    if (sum >= M)
    {
        cout << temp;
        return 0;
    }

    for (int i = 1; i < N; i++)
    {
        sum += meats[i].first;
        if (meats[i].second == meats[i - 1].second)
        {
            temp += meats[i].second;
        }
        else
        {
            temp = meats[i].second;
        }

        if (sum >= M)
        {
            ans = min(ans, temp);
        }
    }

    if (sum < M) cout << -1;
    else cout << ans;

    return 0;
}