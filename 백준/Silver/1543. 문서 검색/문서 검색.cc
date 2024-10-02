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

string str, target;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    getline(cin, str);
    getline(cin, target);
    
    int ans = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        bool flag = true;
        for (int j = 0; j < target.length(); j++) 
        {
            if (str[i + j] != target[j]) 
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            ans++;
            i += target.length() - 1;
        }
    }
    cout << ans;

    return 0;
}