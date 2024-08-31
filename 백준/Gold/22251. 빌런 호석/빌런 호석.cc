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

int N, K, P, X;

struct Num
{
    //0 1 2
    //  3
    //4 5 6
    static bitset<7> Zero()
    {
        bitset<7> result(255);
        result[3] = 0;
        return result;
    }

    static bitset<7> One()
    {
        bitset<7> result;
        result[2] = 1;
        result[6] = 1;
        return result;
    }

    static bitset<7> Two()
    {
        bitset<7> result(255);
        result[0] = 0;
        result[6] = 0;
        return result;
    }

    static bitset<7> Three()
    {
        bitset<7> result(255);
        result[0] = 0;
        result[4] = 0;
        return result;
    }

    static bitset<7> Four()
    {
        bitset<7> result;
        result[0] = 1;
        result[2] = 1;
        result[3] = 1;
        result[6] = 1;
        return result;
    }

    static bitset<7> Five()
    {
        bitset<7> result(255);
        result[2] = 0;
        result[4] = 0;
        return result;
    }

    static bitset<7> Six()
    {
        bitset<7> result(255);
        result[2] = 0;
        return result;
    }

    static bitset<7> Seven()
    {
        bitset<7> result;
        result[1] = 1;
        result[2] = 1;
        result[6] = 1;
        return result;
    }

    static bitset<7> Eight()
    {
        bitset<7> result(255);
        return result;
    }

    static bitset<7> Nine()
    {
        bitset<7> result(255);
        result[4] = 0;
        return result;
    }
};

bitset<7> Get(int n)
{
    switch (n)
    {
    case 0:
        return Num::Zero();
    case 1:
        return Num::One();
    case 2:
        return Num::Two();
    case 3:
        return Num::Three();
    case 4:
        return Num::Four();
    case 5:
        return Num::Five();
    case 6:
        return Num::Six();
    case 7:
        return Num::Seven();
    case 8:
        return Num::Eight();
    case 9:
        return Num::Nine();
    }
}

deque<bitset<7>> makePad(int n)
{
    deque<bitset<7>> result;
    while (n)
    {
        result.push_front(Get(n % 10));
        n /= 10;
    }

    for (int i = result.size(); i < K; i++)
    {
        result.push_front(Get(0));
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> P >> X;

    int ans = 0;
    auto current = makePad(X);
    
    for (int i = 1; i <= N; i++)
    {
        if (i == X) continue;
        auto target = makePad(i);

        int cnt = 0;
        for (int j = 0 ; j < K; j++)
        {
            auto digit = target[j] ^ current[j];
            cnt += digit.count();
        }

        if (cnt <= P) ans++;
    }

    cout << ans;

    return 0;
}