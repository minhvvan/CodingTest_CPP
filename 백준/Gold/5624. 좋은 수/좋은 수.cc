#include <bits/stdc++.h>

using namespace std;

int N;
vector<bool> visited(400'001, false);
vector<int> nums;

int DP() 
{
    int result = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (visited[nums[i] - nums[j] + 200000]) 
            {
                result++;
                break;
            }
        }

        for (int j = 0; j <= i; j++) 
        {
            visited[nums[i] + nums[j] + 200000] = true;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    nums.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    cout << DP();

    return 0;
}