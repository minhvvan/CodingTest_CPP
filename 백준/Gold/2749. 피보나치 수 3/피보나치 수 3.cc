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

using namespace std;

long long N;
const int M = 1'000'000;
const int P = 15 * (M / 10);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> nums(P);
    if (N == 0) cout << 0;
    else if (N == 1) cout << 1;
    else
    {
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i < P; i++)
        {
            nums[i] = (nums[i - 1] + nums[i - 2]) % M;
        }
        cout << nums[N % P];
    }

    return 0;
}