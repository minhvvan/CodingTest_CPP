#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> M;

    priority_queue<long long, vector<long long>, greater<long long>> nums;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        nums.push(a);
    }

    for (int i = 0; i < M; i++)
    {
        long long int a = nums.top();
        nums.pop();

        long long int b = nums.top();
        nums.pop();

        long long int c = a + b;
        nums.push(c);
        nums.push(c);
    }

    long long int ans = 0;
    while (!nums.empty())
    {
        ans += nums.top();
        nums.pop();
    }

    cout << ans;

    return 0;
}