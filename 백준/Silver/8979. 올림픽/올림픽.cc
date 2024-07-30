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
int N, K;

struct Country
{
    Country(int n, int g, int s, int b) :
        number(n),
        gold(g),
        silver(s),
        bronze(b)
    {

    };

    int number;
    int gold;
    int silver;
    int bronze;

    bool operator==(const Country& Other) const
    {
        return gold == Other.gold && silver == Other.silver && bronze == Other.bronze;
    }

    bool operator!=(const Country& Other) const
    {
        return gold != Other.gold || silver != Other.silver || bronze != Other.bronze;
    }
};

bool cmp(const Country& a, const Country& b)
{
    if (a.gold != b.gold) return a.gold > b.gold;
    if (a.silver != b.silver) return a.silver > b.silver;
    return a.bronze > b.bronze;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    vector<Country> Countries;
    for (int i = 0; i < N; i++)
    {
        int n, g, s, b;
        cin >> n >> g >> s >> b;

        Country temp(n, g, s, b);
        Countries.push_back(temp);
    }

    sort(Countries.begin(), Countries.end(), cmp);

    if (Countries[0].number == K)
    {
        cout << 1;
        return 0;
    }

    int ans = 1;
    int increase = 1;
    for (int i = 1; i < N; i++)
    {
        if (Countries[i - 1] == Countries[i])
        {
            increase++;
        }
        else
        {
            ans += increase;
            increase = 1;
        }

        if (Countries[i].number == K)
        {
            cout << ans;
            break;
        }
    }

    return 0;
}