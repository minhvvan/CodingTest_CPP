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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        vector<int> Nums;
        int a, b, c;

        cin >> a >> b >> c;

        if (a == 0) break;
        Nums.push_back(a);
        Nums.push_back(b);
        Nums.push_back(c);

        sort(Nums.begin(), Nums.end());
        if (Nums[2] >= Nums[1] + Nums[0])
        {
            cout << "Invalid\n";
            continue;
        }

        if (a == b && b == c) cout << "Equilateral\n";
        else if ((a == b && b != c) || (b == c && a != b) || (a == c && a != b)) cout << "Isosceles\n";
        else if (a != b && b != c) cout << "Scalene\n";
    }
    

    return 0;
}