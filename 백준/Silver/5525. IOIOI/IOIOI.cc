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

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int k = 0;

        if (S[i] == 'O')
        {
            continue;
        }
        else
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                k++;
                if (k == N)
                {
                    k--;
                    ans++;
                }

                i += 2;
            }
        }
    }

    cout << ans;

    return 0;
}