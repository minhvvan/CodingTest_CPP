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
string start, target, current;
int ans = INT_MAX;

void lightOn(int idx)
{
     current[idx - 1] = current[idx - 1] == '0' ? '1' : '0';
    current[idx] = current[idx] == '0' ? '1' : '0';
    if (idx < N-1) current[idx + 1] = current[idx + 1] == '0' ? '1' : '0';
}

void solve(int startIdx)
{
    current = start;
    int cnt = 0;

    if (startIdx == 0)
    {
        current[0] = current[0] == '0' ? '1' : '0';
        current[1] = current[1] == '0' ? '1' : '0';
        cnt++;
    }

    for (int i = 1; i < N; i++)
    {
        if (current[i - 1] != target[i - 1])
        {
            lightOn(i);
            cnt++;
        }
    }

    if (current == target) ans = min(ans, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> start >> target;

    solve(0);
    solve(1);

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}