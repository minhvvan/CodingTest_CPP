#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;
vector<int> sum;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;
    
    nums.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            sum.push_back(nums[i] + nums[j]);
        }
    }

    sort(sum.begin(), sum.end());

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int num = nums[i] - nums[j];
            if (binary_search(sum.begin(), sum.end(), num))
            {
                cout << nums[i];
                return 0;
            }
        }
    }

    return 0;
} 