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
#include <bitset>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    multimap<int, string> titles;
    for (int i = 0; i < N; i++) 
    {
        string t;
        int p;
        cin >> t >> p;
        titles.insert({ p,t });
    }

    for (int i = 0; i < M; i++) 
    {
        int power; 
        cin >> power;
        cout << titles.lower_bound(power)->second << '\n';
    }

    return 0;
}