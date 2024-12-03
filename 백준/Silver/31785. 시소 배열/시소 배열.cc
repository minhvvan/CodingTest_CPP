#include <bits/stdc++.h>

using namespace std;

int Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> Q;

    deque<int> nums;
    deque<int> sums;
    for (int i = 0; i < Q; i++)
    {
        int oper;
        cin >> oper;

        if (oper == 1)
        {
            int num;
            cin >> num;

            nums.push_back(num);
            if (sums.empty()) sums.push_back(num);
            else sums.push_back(sums.back() + num);
        }
        else
        {
            int mid = sums.size() / 2;

            int front = sums[mid-1];
            int back = sums[sums.size() - 1] - sums[mid-1];

            if (front <= back)
            {
                //앞 삭제
                int cnt = 0;
                while (cnt++ < mid)
                {
                    sums.pop_front();
                    nums.pop_front();
                }

                for (auto& sum : sums)
                {
                    sum -= front;
                }

                cout << front << "\n";
            }
            else
            {
                //뒤 삭제
                nums.resize(mid);
                sums.resize(mid);
                cout << back << "\n";
            }
        }
    }

    for (auto num : nums)
    {
        cout << num << " ";
    }

    return 0;
}