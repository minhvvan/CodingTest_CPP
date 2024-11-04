#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        priority_queue<int> A;
        priority_queue<int> B;

        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            A.push(a);
        }
        
        for (int i = 0; i < M; i++)
        {
            int b;
            cin >> b;
            B.push(b);
        }

        int ans = 0;
        while (!A.empty() && !B.empty())
        {
            int a = A.top();
            int b = B.top();

            if (a > b)
            {
                ans += B.size();
                A.pop();
            }
            else
            {
                B.pop();
            }
        }

        cout << ans << "\n";
    }

    return 0;
}