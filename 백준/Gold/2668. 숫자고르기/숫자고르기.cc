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

int N;
vector<int> nums;

set<int> getMax(int start)
{
    set<int> visited;
    set<int> targets;

    while (true)
    {
        if (start == nums[start]) break;
        if (visited.count(start)) break;

        targets.insert(nums[start]);
        visited.insert(start);

        start = nums[start];
    }

    if (targets.size() != visited.size()) return set<int>();

    auto itr1 = targets.begin();
    auto itr2 = visited.begin();
    for (; itr1 != targets.end(); itr1++, itr2++)
    {
        if (*itr1 != *itr2) return set<int>();
    }

    return visited;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    nums.resize(N + 1);
    set<int> ans;

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        if (i == nums[i]) ans.insert(i);
    }

    for (int i = 1; i <= N; i++)
    {
        auto result = getMax(i);
        ans.merge(result);
    }

    cout << ans.size() << "\n";
    for (auto num : ans)
    {
        cout << num << "\n";
    }

    return 0;
}