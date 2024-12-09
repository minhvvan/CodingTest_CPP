#include <bits/stdc++.h>

using namespace std;

vector<int> colors;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    colors.resize(3);
    int minColor = INT_MAX;
    int minIdx = -1;
    for (int i = 0; i < 3; i++)
    {
        cin >> colors[i];
        if (colors[i] < minColor)
        {
            minColor = min(minColor, colors[i]);
            minIdx = i;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        colors[i] -= minColor;
    }

    int ans = minColor;
    for (int i = 0; i < 3; i++)
    {
        if (colors[i] == 0) continue;

        while (1 < colors[i])
        {
            ans++;
            colors[i] -= min(3, colors[i]);
        }
    }

    if (colors[0] == 1 || colors[1] == 1 || colors[2] == 1) ans++;
    cout << ans;

    return 0;
}