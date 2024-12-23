#include <bits/stdc++.h>

using namespace std;

int N;
int sum = 0, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        sum += num;
        cnt += num / 2;
    }

    if (sum % 3 || cnt < sum / 3) 
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}