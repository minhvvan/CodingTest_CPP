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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> Nums(N*N, 0);
    for (int i = 0; i < N * N; i++)
    {
        cin >> Nums[i];
    }

    sort(Nums.begin(), Nums.end(), greater());

    cout << Nums[N - 1];

    return 0;
}