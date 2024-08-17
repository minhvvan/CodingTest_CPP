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

int N, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    deque<int> dq;
    map<int, int> window;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        while (!dq.empty() && window[num] >= K)
        {
            int front = dq.front();
            dq.pop_front();

            window[front]--;
        }

        dq.push_back(num);
        window[num]++;

        ans = max(ans, (int)dq.size());
    }

    cout << ans;

    return 0;
}