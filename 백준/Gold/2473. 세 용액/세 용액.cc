#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N;

    vector<int> solutions(N);

    for (int i = 0; i < N; i++)
    {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    long long minDiff = LLONG_MAX;
    vector<int> ans;

    for (int i = 0; i < N; i++)
    {
        long long sum = solutions[i];

        int left = 0;
        if (left == i) left++;
        int right = N-1;
        if (right == i) right--;

        sum += solutions[left];
        sum += solutions[right];
        while (left < right && right < N)
        {
            if (abs(sum) < minDiff)
            {
                minDiff = abs(sum);
                ans.clear();
                ans.push_back(solutions[i]);
                ans.push_back(solutions[left]);
                ans.push_back(solutions[right]);
            }
            else if (sum > 0)
            {
                sum -= solutions[right];
                right--;
                if (right == i) right--;
                sum += solutions[right];
            }
            else
            {
                sum -= solutions[left];
                left++;
                if (left == i) left++;
                sum += solutions[left];
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (auto num : ans)
    {
        cout << num << " ";
    }

    return 0;
}