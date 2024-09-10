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
vector<bool> visited(100'000 + 1);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    long long ans = 0;
    int start = 0, end = 0;
    for (; start < N; start++)
    {
        while (end < N)
        {
            if (visited[nums[end]]) break;
            visited[nums[end]] = 1;
            end++;
        }

        ans += (end - start);
        visited[nums[start]] = 0;
    }

    cout << ans;
    return 0;
}