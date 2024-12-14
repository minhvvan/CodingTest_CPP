#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;
set<vector<int>> numSet;

void make(int start, vector<int>& temp)
{
    if (temp.size() == M)
    {
        if (numSet.count(temp) != 0) return;
        numSet.insert(temp);

        for (auto t : temp)
        {
            cout << t << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        make(start, temp);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    nums.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> temp;
    for (int i = 0 ; i < nums.size(); i++)
    {
        make(i, temp);
    }

    return 0;
}