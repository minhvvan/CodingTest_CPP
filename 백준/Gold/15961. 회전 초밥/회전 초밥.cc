#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> d >> k >> c;

    vector<int> sushies(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sushies[i];
    }

    vector<int> check(d+1, 0);
    deque<int> current;

    check[c] = 1;
    int ans = 1;
    int cnt = 1;

    for (int i = 0; i < k; i++)
    {
        int sushi = sushies[i];
        current.push_back(sushi);
        check[sushi]++;
        if (check[sushi] == 1) cnt++;
    }

    ans = max(ans, cnt);

    for (int i = k; i < N + k; i++)
    {
        int front = current.front();
        current.pop_front();
        check[front]--;
        if (check[front] == 0) cnt--;

        int sushi = sushies[i % N];
        current.push_back(sushi);
        check[sushi]++;
        if (check[sushi] == 1) cnt++;

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}