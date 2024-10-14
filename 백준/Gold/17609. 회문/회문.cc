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
string str;

int IsPalindrome(int left, int right, int result)
{
    if (left >= right) return result;

    if (str[left] == str[right])
    {
        result = IsPalindrome(left + 1, right - 1, result);
    }
    else if (str[left + 1] == str[right] && str[left] == str[right - 1])
    {
        result = min(IsPalindrome(left + 1, right, result + 1), IsPalindrome(left, right - 1, result + 1));
    }
    else if (str[left + 1] == str[right])
    {
        result = IsPalindrome(left + 1, right, result + 1);
    }
    else if (str[left] == str[right - 1])
    {
        result = IsPalindrome(left, right - 1, result + 1);
    }
    else
    {
        result = 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    while (N--)
    {
        cin >> str;
        int result = IsPalindrome(0, str.length() - 1, 0);
        cout << result << "\n";
    }

    return 0;
}