#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> T;

    while (T--)
    {
        int K;
        cin >> K >> N;

        vector<int> origin(N);
        vector<int> nums(N);

        int minNum = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            cin >> nums[i];
            origin[i] = nums[i];
            minNum = min(minNum, nums[i]);
        }

        //가장 작은 숫자부터 선택해서 뒤에 넣어야 함
        //근데 이미 앞에서부터 작은 숫자가 들어가 있으면 할 필요 없음
        sort(nums.begin(), nums.end());

        //정렬되어 있는 숫자들 파악
        int target = minNum;
        int cursor = 0;
        for (int i = 0; i < N; i++)
        {
            if (target == origin[i])
            {
                target = nums[++cursor];
            }
        }

        cout << K << " " << N - cursor << "\n";
    }


    return 0;
}