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

    deque<long long> cards(N);
    deque<long long> temp;
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    sort(cards.begin(), cards.end());

    long long ans = 0;

    while (cards.size() + temp.size() > 1)
    {
        long long a;
        long long b;

        //find a
        if (temp.empty())
        {
            a = cards.front();
            cards.pop_front();
        }
        else
        {
            if (cards.empty())
            {
                a = temp.front();
                temp.pop_front();
            }
            else if (temp.front() < cards.front())
            {
                a = temp.front();
                temp.pop_front();
            }
            else
            {
                a = cards.front();
                cards.pop_front();
            }
        }

        //find b
        if (temp.empty())
        {
            b = cards.front();
            cards.pop_front();
        }
        else
        {
            if (cards.empty())
            {
                b = temp.front();
                temp.pop_front();
            }
            else if (temp.front() < cards.front())
            {
                b = temp.front();
                temp.pop_front();
            }
            else
            {
                b = cards.front();
                cards.pop_front();
            }
        }

        ans += a + b;
        temp.push_back(a + b);
    }

    cout << ans;

    return 0;
}