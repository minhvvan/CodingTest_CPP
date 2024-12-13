#include <bits/stdc++.h>

using namespace std;

long long X1, X2, Y1, Y2, R1, R2;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> X1 >> Y1 >> R1;
    cin >> X2 >> Y2 >> R2;

    if ((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1) < (R1 + R2) * (R1 + R2)) cout << "YES";
    else cout << "NO";

    return 0;
}