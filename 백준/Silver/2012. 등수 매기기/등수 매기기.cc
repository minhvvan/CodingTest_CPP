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
vector<int> grades;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;
    grades.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> grades[i];
    }
    
    sort(grades.begin() + 1, grades.end());

    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += abs(i - grades[i]);
    }

    cout << ans;
    return 0;
}