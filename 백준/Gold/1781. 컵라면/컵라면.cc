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
vector<pair<int, int>> problems;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;
    problems.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;

        //{deadline, reward}
        problems[i] = { a,b };
    }

    sort(problems.begin(), problems.end(), cmp);

    int idx = N;
    long long ans = 0;

    priority_queue<int> pq;

    for (int i = N; i > 0; i--)
    {
        while (idx > 0 && problems[idx].first >= i)
        {
            pq.push(problems[idx].second);
            idx--;
        }

        if (pq.empty()) continue;
        
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}