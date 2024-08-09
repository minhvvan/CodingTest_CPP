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
#include <bitset>

using namespace std;

string N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    const int size = N.length();
    bitset<500> checkCnt(N);

    int oneCntHalf = checkCnt.count() / 2;
    int zeroCntHalf = (size - checkCnt.count()) / 2;

    string ans;
    int oneCnt = 0;
    int zeroCnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (N[i] == '0')
        {
            if (zeroCnt >= zeroCntHalf) continue;

            zeroCnt++;
            ans += N[i];
        }
        else 
        {
            if (oneCnt < oneCntHalf)
            {
                oneCnt++;
                continue;
            }
            else
            {
                ans += N[i];
            }
        }
    }

    cout << ans;

    return 0;
}