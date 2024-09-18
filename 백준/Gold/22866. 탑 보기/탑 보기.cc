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

    cin >> N;
    vector<int> buildings(N + 1);
    vector<int> near(N + 1, 0);
    vector<int> cnt(N + 1, 0);
    vector<pair<int,int>> stack;

    for (int i = 1; i <= N; i++)
    {
        cin >> buildings[i];
    }

    //left
    for (int i = 1; i <= N; i++)
    {
        while (!stack.empty() && stack.back().second <= buildings[i]) stack.pop_back();
        cnt[i] += stack.size();

        if (!stack.empty())
        {
            if (near[i] == 0)
            {
                near[i] = stack.back().first;
            }
            else if (abs(near[i] - i) > abs(stack.back().first - i))
            {
                near[i] = stack.back().first;
            }
        }

        stack.push_back({ i, buildings[i] });
    }

    stack.clear();

    //right
    for (int i = N; i > 0; i--)
    {
        while (!stack.empty() && stack.back().second <= buildings[i]) stack.pop_back();
        cnt[i] += stack.size();

        if (!stack.empty())
        {
            if (near[i] == 0)
            {
                near[i] = stack.back().first;
            }
            else if (abs(near[i] - i) > abs(stack.back().first - i))
            {
                near[i] = stack.back().first;
            }
        }
        stack.push_back({ i, buildings[i] });
    }

    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0) cout << 0 << '\n';
        else cout << cnt[i] << ' ' << near[i] << '\n';
    }

    return 0;
}