#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> lights;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    lights.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> lights[i];
    }

    vector<int> groups;
    int cnt = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (lights[i] != lights[i + 1]) cnt++;
        else
        {
            groups.push_back(cnt);
            cnt = 1;
        }
    }

    if(cnt != 0) groups.push_back(cnt);

    int ans = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int cnt = groups[i];
        if (i != 0) cnt += groups[i - 1];
        if (i != groups.size()-1) cnt += groups[i + 1];

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}