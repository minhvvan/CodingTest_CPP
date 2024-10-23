#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M;

    vector<int> nums(N+1, 0);
    vector<int> sums(N+1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        sums[i] = sums[i - 1] + nums[i];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sums[b] - sums[a-1] << "\n";
    }

    return 0;
}