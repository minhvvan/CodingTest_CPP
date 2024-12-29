#include <bits/stdc++.h>

using namespace std;

int N,  M;
string S, P;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> N >> M >> S;

    for (int i = 0; i < 2 * N + 1; i++)
    {
        if (i % 2 == 0) P += 'I';
        else P += 'O';
    }

    string current;
    for (int i = 0; i < 2 * N + 1; i++)
    {
        current += S[i];
    }

    int ans = 0;
    if (current == P) ans++;

    for (int i = 2 * N + 1; i < M; i++)
    {
        current = current.substr(1, current.length());
        current += S[i];

        if (current == P) ans++;
    }

    cout << ans;

    return 0;
}