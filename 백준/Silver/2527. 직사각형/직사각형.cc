#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
struct Rect
{
    int ly, lx, ry, rx;

    Rect(int a, int b, int c, int d) : ly(a), lx(b), ry(c), rx(d)
    { }
};

int main() 
{
    INPUT_OPTIMIZE;
    
    int T = 4;
    while (T--)
    {
        int x1, y1, p1, q1, x2, y2, p2, q2;
        int xr, xl, yb, yt, xdiff, ydiff;

        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

        xl = max(x1, x2);
        xr = min(p1, p2);
        yb = max(y1, y2);
        yt = min(q1, q2);

        xdiff = xr - xl;
        ydiff = yt - yb;

        if (xdiff > 0 && ydiff > 0)cout << 'a' << endl;
        else if (xdiff < 0 || ydiff < 0)cout << 'd' << endl;
        else if (xdiff == 0 && ydiff == 0)cout << 'c' << endl;
        else cout << 'b' << endl;
    }

	return 0;
} 