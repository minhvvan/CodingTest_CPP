#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> N;
    nums.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    //이진탐색을 이용하는 방법
    //pos를 구한뒤 업데이트
    vector<int> LIS(N, 0);

    int len = 0;
    for (int i = 0; i < N; i++)
    {
        int num = nums[i];

        int pos = lower_bound(LIS.begin(), LIS.begin() + len, num) - LIS.begin();
        LIS[pos] = num;

        if (pos + 1 > len) len++;
    }

    cout << len;

    return 0;
}