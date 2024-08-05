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

int N, X;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X;

    vector<int> sum(N, 0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (i == 0) sum[i] = num;
        else sum[i] += sum[i - 1] + num;
    }

    pair<int, int> ans = { sum[X-1], 1 };
    for (int i = 1; i <= N - X; i++)
    {
        int total = sum[i + X - 1] - sum[i - 1];
        if (ans.first == total)
        {
            ans.second++;
            continue;
        }
        else if (ans.first < total)
        {
            ans.first = total;
            ans.second = 1;
        }
    }

    if (ans.first == 0) cout << "SAD";
    else cout << ans.first << "\n" << ans.second;

    return 0;
}