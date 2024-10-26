#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> prime = {0};
vector<int> sumStack = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N;

    long long ans = 0;

    for (int i = 2; i <= N; i++)
    {
        bool bPrime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                bPrime = false;
                break;
            }
        }

        if (bPrime)
        {
            prime.push_back(i);
            sumStack.push_back(sumStack.back() + i);
        }
    }

    int left = 1;
    int right = 1;

    while (right < prime.size())
    {
        int sum = sumStack[right] - sumStack[left - 1];

        if (sum == N)
        {
            ans++;
            right++;
        }
        else if (sum > N) left++;
        else right++;
    }

    cout << ans;

    return 0;
}