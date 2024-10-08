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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    vector<int> students(2 * N);
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> students[i];
    }

    sort(students.begin(), students.end());

    //1 2 3 5 7 9
    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        ans = min(ans, students[i] + students[2 * N - i - 1]);
    }

    cout << ans;

    return 0;
}