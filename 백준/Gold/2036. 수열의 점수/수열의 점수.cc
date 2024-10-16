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

    deque<long long> negativeNums;
    deque<long long> positiveNums;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num <= 0) negativeNums.push_back(num);
        else positiveNums.push_back(num);
    }

    sort(negativeNums.begin(), negativeNums.end());
    sort(positiveNums.begin(), positiveNums.end());

    long long ans = 0;
    
    while (!negativeNums.empty())
    {
        long long a = negativeNums.front();
        negativeNums.pop_front();

        if (!negativeNums.empty())
        {
            long long b = negativeNums.front();
            negativeNums.pop_front();

            a *= b;
        }

        ans += a;
    }

    while (!positiveNums.empty())
    {
        long long a = positiveNums.back();
        positiveNums.pop_back();

        if (a == 0) break;

        if (!positiveNums.empty())
        {
            if (positiveNums.back() > 1)
            {
                long long b = positiveNums.back();
                positiveNums.pop_back();

                a *= b;
            }
        }

        ans += a;
    }

    cout << ans;

    return 0;
}