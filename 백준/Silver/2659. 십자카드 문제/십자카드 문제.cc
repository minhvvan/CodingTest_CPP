#include <bits/stdc++.h>

using namespace std;

int N, M;

int makeCircle(vector<int>& nums)
{
    vector<int> circleNum;
    for (int i = 0; i < 4; i++)
    {
        int num = 0;

        for (int j = 0; j < 4; j++)
        {
            num *= 10;
            num += nums[(i + j) % 4];
        }

        circleNum.push_back(num);
    }

    sort(circleNum.begin(), circleNum.end());
    return circleNum[0];
}

int GetOrder(int num)
{
    vector<int> current(4, 1);
    set<int> circleNums;

    int cnt = 0;

    int circleNum = makeCircle(current);
    while (circleNum < num)
    {
        circleNums.insert(circleNum);
     
        int idx = 3;
        current[idx]++;
        while (true)
        {
            if (current[idx] == 10)
            {
                current[idx] = 1;
                idx--;
                if (idx < 0) break;
                current[idx]++;
            }
            else break;
        }

        circleNum = makeCircle(current);
    }

    return circleNums.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    vector<int> nums(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> nums[i];
    }
    
    vector<int> circleNum;
    for (int i = 0; i < 4; i++)
    {
        int num = 0;

        for (int j = 0; j < 4; j++)
        {
            num *= 10;
            num += nums[(i + j) % 4];
        }

        circleNum.push_back(num);
    }

    sort(circleNum.begin(), circleNum.end());

    cout << GetOrder(circleNum[0]) + 1;

    return 0;
}