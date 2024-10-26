#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> hits;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);
    
    cin >> N;

    hits.resize(N, vector<int>(9));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> hits[i][j];
        }
    }

    vector<int> per = { 0,1,2,3,4,5,6,7,8 };

    int ans = 0;
    do 
    {
        if (per[3] != 0) continue;

        int score = 0;
        int idx = 0;
        for (int t = 0; t < N; t++)
        {
            int out = 0;
            vector<bool> base(4, false);
            while (out < 3)
            {
                int hit = hits[t][per[idx]];
                idx = (idx + 1) % 9;
                if (hit == 0)
                {
                    out++;
                    continue;
                }

                //주자 
                for (int i = 3; i > 0; i--)
                {
                    if (!base[i]) continue;

                    int newIdx = i + hit;
                    if (newIdx > 3) score++;
                    else base[newIdx] = true;

                    base[i] = false;
                }

                //타자
                if (hit == 4) score++;
                else base[hit] = true;
            }
        }

        ans = max(ans, score);

    } while (next_permutation(per.begin(), per.end()));

    cout << ans;
    
    return 0;
}