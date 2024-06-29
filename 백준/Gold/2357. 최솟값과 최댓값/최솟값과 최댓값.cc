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

int N, M;
const int MAX = 1'000'000'001;
const int MIN = 0;

int findMin(vector<int>& Nums, int a, int b)
{
    a += N;
    b += N;
    int ans = MAX;
    while (a <= b)
    {
        if (a % 2 == 1) ans = min(ans, Nums[a++]);
        if (b % 2 == 0) ans = min(ans, Nums[b--]);

        a /= 2;
        b /= 2;
    }

    return ans;
}

int findMax(vector<int>& Nums, int a, int b)
{
    a += N;
    b += N;
    int ans = MIN;
    while (a <= b)
    {
        if (a % 2 == 1) ans = max(ans, Nums[a++]);
        if (b % 2 == 0) ans = max(ans, Nums[b--]);

        a /= 2;
        b /= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int temp = 1;
    while (temp < N)
    {
        temp *= 2;
    }

    vector<int> minNums(2*temp, MAX);
    vector<int> maxNums(2*temp, MIN);
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        minNums[i+temp] = input;
        maxNums[i+temp] = input;
    }

    N = temp;

    for (int i = N-1; i > 0; i--)
    {
        minNums[i] = min(minNums[2 * i], minNums[2 * i + 1]);
        maxNums[i] = max(maxNums[2 * i], maxNums[2 * i + 1]);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << findMin(minNums, a-1, b-1) << " " << findMax(maxNums, a-1, b-1) << "\n";
    }

    return 0;
}