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

int N, M;
const int MAX = 36;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    vector<vector<int>> lectures;
    vector<int> limits;
    vector<int> minMileage;
    lectures.resize(N);
    minMileage.resize(N);

    for (int i = 0; i < N; i++)
    {
        int p, l;

        cin >> p >> l;
        lectures[i].resize(p);

        for (int j = 0; j < p; j++)
        {
            cin >> lectures[i][j];
        }

        sort(lectures[i].begin(), lectures[i].end());
        if (p < l)
        {
            minMileage[i] = 1;
        }
        else
        {
            minMileage[i] = lectures[i][p - l];
        }
    }

    sort(minMileage.begin(), minMileage.end());

    int ans = 0;
    for(int i = 0 ; i < N; i++)
    {
        if (M >= minMileage[i])
        {
            M -= minMileage[i];
            ans++;
        }
        else
        {
            break;
        }
    }

    cout << ans;

    return 0;
}