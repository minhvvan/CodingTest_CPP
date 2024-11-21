#include <bits/stdc++.h>

using namespace std;

int N, H;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> H;

    vector<int> over;
    vector<int> under;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0) under.push_back(num);
        else over.push_back(num);
    }

    sort(under.begin(), under.end());
    sort(over.begin(), over.end());

    int minDestroy = INT_MAX;
    int cnt = 0;
    int half = N / 2;
    for (int i = 1; i <= H; i++)
    {
        int up = lower_bound(over.begin(), over.end(), H - i + 1) - over.begin();
        int down = lower_bound(under.begin(), under.end(), i) - under.begin();

        int current = N - up - down;
        if (minDestroy == current) cnt++;
        else if (minDestroy > current)
        {
            minDestroy = current;
            cnt = 1;
        }
    }

    cout << minDestroy << " " << cnt;

    return 0;
}