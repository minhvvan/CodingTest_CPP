#include <bits/stdc++.h>

using namespace std;

float N;
vector<pair<float, float>> dots;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N;

    for (int i = 0; i < 3; i++)
    {
        float a, b;
        cin >> a >> b;

        dots.push_back({ min(a,b), max(a,b) });
    }
    
    float start = 0;
    float end = N;
    for (int i = 0; i < 3; i++)
    {
        auto [a, b] = dots[i];
        if (a == b) continue;

        float mid = (a + b) / 2.f;

        for (int j = i + 1; j < 3; j++)
        {
            auto& [x, y] = dots[j];
            if (x == y) continue;

            x = mid + fabs(mid - x);
            y = mid + fabs(mid - y);
        }

        start = mid + fabs(mid - start);
        if (start > end) end = start;
        start = mid;
    }

    cout << end - start;

    return 0;
}