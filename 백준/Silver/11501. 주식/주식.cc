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

int T, N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) 
    {
        cin >> N;
        vector<int> stocks;

        for (int i = 0; i < N; i++) 
        {
            int x;
            cin >> x;
            stocks.push_back(x);
        }

        long long result = 0;
        int max_value = -1;

        for (int i = N - 1; i >= 0; i--) 
        {
            max_value = max(max_value, stocks[i]);
            result += max_value - stocks[i];
        }

        cout << result << "\n";
    }

    return 0;
}