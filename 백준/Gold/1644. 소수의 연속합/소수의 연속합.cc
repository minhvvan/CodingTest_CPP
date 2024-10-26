#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> prime;

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
        for (int j = 2; j * j <= i; j++)
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
        }
    }

    int left = 0;
    int right = 0;

    int sum = 0;
    while (right <= prime.size())
    {
        if (sum >= N) 
        {
            if (sum == N) ans++;
            sum -= prime[left++];
        }
        else 
        {
            if (right < prime.size()) 
            {
                sum += prime[right];
            }

            right++;
        }
    }

    cout << ans;

    return 0;
}