#include <bits/stdc++.h>

using namespace std;

int N, L, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> L >> M;

    vector<pair<int, int>> fishes;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        fishes.push_back({ a,b });
    }

    sort(fishes.begin(), fishes.end());

    int ans = 0;
    //w: 가로
    for (int w = 1; w < L / 2; w++)
    {
        int h = L / 2 - w;

        if (w > N - 1 || h > N - 1) continue;
        for (int f = 0; f < M; f++)
        {
            auto [fishY, fishX] = fishes[f];

            for (int k = 0; k <= w; k++)
            {
                int cnt = 1;
                for (int nextFish = f + 1; nextFish < M; nextFish++)
                {
                    auto [nextY, nextX] = fishes[nextFish];

                    if (nextY > fishY + h) break;
                    if (fishX-k <= nextX && nextX <= fishX+w-k) cnt++;
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans;

    return 0;
}