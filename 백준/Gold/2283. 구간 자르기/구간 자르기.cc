#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> K;

    vector<int> lines(1'000'001, 0);

    int maxEnd = 0;
    int minStart = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        minStart = min(minStart, a);
        maxEnd = max(maxEnd, b);

        for (int j = a; j < b; j++)
        {
            lines[j]++;
        }
    }

    int left = 0;
    int right = 1;

    vector<int> sums(maxEnd + 1, 0);
    for (int i = left; i <= maxEnd; i++)
    {
        if (i == 0) sums[i] = lines[i];
        else sums[i] = sums[i - 1] + lines[i];
    }

    bool bPossible = false;
    while (right <= maxEnd)
    {
        int length;
        if (left == 0) length = sums[right - 1];
        else length = sums[right - 1] - sums[left - 1];

        if (length == K)
        {
            bPossible = true;
            break;
        }
        else if (length < K) right++;
        else left++;
    }

    if (bPossible) cout << left << " " << right;
    else cout << "0 0";

    return 0;
}