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

        lines[a]++;
        lines[b]--;
    }

    int left = 0;
    int right = 1;

    for (int i = 1; i <= maxEnd; i++)
    {
        lines[i] += lines[i - 1];
    }

    bool bPossible = false;
    int length = lines[0];
    while (right <= maxEnd)
    {
        if (length == K)
        {
            cout << left << " " << right;
            return 0;
        }
        else if (length < K)
        {
            length += lines[right++];
        }
        else
        {
            length -= lines[left++];
        }
    }

    cout << "0 0";

    return 0;
}