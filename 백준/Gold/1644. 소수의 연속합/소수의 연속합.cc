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

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
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