#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int A, B, C, D;

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> A >> B >> C >> D;

    int gcd = GCD(B, D);
    int parent = B * D / gcd;

    A *= parent / B;
    C *= parent / D;

    int child = A + C;

    while (true)
    {
        auto a = GCD(child, parent);
        if (a == 1) break;

        child /= a;
        parent /= a;
    }

    cout << child << " " << parent;

    return 0;
} 