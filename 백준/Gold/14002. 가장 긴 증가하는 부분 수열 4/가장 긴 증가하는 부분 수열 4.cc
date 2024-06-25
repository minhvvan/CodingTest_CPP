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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> nums(N);
    vector<int> length(N, 0);
    vector<int> select(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int cursor = 0;

    for (int k = 0; k < N; k++)
    {
        length[k] = 1;
        select[k] = k;
        for (int i = 0; i < k; i++)
        {
            if (nums[i] < nums[k])
            {
                if (length[k] < length[i] + 1)
                {
                    length[k] = length[i] + 1;
                    select[k] = i;

                    if (length[cursor] < length[k]) cursor = k;
                }
            }
        }
    }

    vector<int> selectedNum;
    selectedNum.push_back(cursor);
    cout << length[cursor] << "\n";

    while (cursor != select[cursor])
    {
        selectedNum.push_back(select[cursor]);
        cursor = select[cursor];
    }

    for (int i = selectedNum.size() - 1; i >= 0; i--)
    {
        cout << nums[selectedNum[i]] << " ";
    }

    return 0;
}