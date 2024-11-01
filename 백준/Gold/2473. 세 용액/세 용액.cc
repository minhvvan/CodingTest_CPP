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

    vector<long long> solutions(N);

    for (int i = 0; i < N; i++)
    {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    long long minDiff = LLONG_MAX;
    vector<int> ans;

    for (int i = 0; i < N-2; i++)
    {
        int left = i+1;
        int right = N-1;

        while (left < right)
        {
            long long sum = solutions[i] + solutions[left] + solutions[right];

            if (abs(sum) < minDiff)
            {
                minDiff = abs(sum);
                ans.clear();
                ans.push_back(solutions[i]);
                ans.push_back(solutions[left]);
                ans.push_back(solutions[right]);
            }
            
            if (sum == 0) break;
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                left++;
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