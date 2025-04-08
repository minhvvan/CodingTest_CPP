#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> nums;

int GCD(int a, int b)
{
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return GCD(b, a - b);
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    nums.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), greater<int>());

    int gcd = nums[0] - nums[1];
    for (int i = 1; i < N-1; i++)
    {
        gcd = GCD(gcd, nums[i] - nums[i + 1]);
    }

    vector<int> ans;
    for (int i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            if(i != 1) ans.push_back(i);
            if (gcd / i != i) ans.push_back(gcd / i);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto num : ans)
    {
        cout << num << " ";
    }

    return 0;
}