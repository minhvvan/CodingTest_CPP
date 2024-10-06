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
vector<pair<int,int>> people;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    long long total = 0;
    for (int i = 0; i < N; i++)
    {
        int x, a;
        cin >> x >> a;

        total += a;
        people.push_back({ x, a });
    }

    sort(people.begin(), people.end());

    long long current = 0;
    for (int i = 0 ; i < N; i++)
    {
        current += people[i].second;

        if (current >= (total + 1) / 2)
        {
            cout << people[i].first;
            break;
        }
    }

    return 0;
}