#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> cards;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    cards.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end(), greater());

    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans += cards[0] + cards[i];
    }

    cout << ans;

    return 0;
}