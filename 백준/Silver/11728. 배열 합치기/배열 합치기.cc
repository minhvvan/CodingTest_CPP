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

    queue<int> A;
    queue<int> B;

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

    vector<int> result;
    while (!A.empty() || !B.empty())
    {
        if (A.empty())
        {
            result.push_back(B.front());
            B.pop();
        }
        else if (B.empty())
        {
            result.push_back(A.front());
            A.pop();
        }
        else
        {
            int a = A.front();
            int b = B.front();

            if (a <= b)
            {
                result.push_back(a);
                A.pop();
            }
            else
            {
                result.push_back(b);
                B.pop();
            }
        }
    }

    for (auto num : result)
    {
        cout << num << " ";
    }


    return 0;
}